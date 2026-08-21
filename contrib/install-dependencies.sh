#!/usr/bin/env bash
# Satoxcoin Core — install missing build dependencies (opt-in, prompted sudo)
# Usage: ./contrib/install-dependencies.sh [--dry-run] [--yes] [--with-gui] [--without-gui] [--without-wallet] [--with-zmq] [--with-ipc]
#   --dry-run   : print what would be installed, do not run sudo
#   --yes, -y   : do not prompt, assume yes (for CI)
#   --with-gui  : include Qt6 + qrencode + libgl (default: without GUI, matching Docker)
#   --without-gui : explicitly skip GUI deps
#   --without-wallet : skip sqlite
#   --with-zmq  : include libzmq
#   --with-ipc  : include capnproto
#
# Supports Ubuntu/Debian (apt) as primary; Fedora (dnf), Arch (pacman), Alpine (apk) as best-effort.
# Idempotent: re-running when satisfied prints "All dependencies satisfied."

set -euo pipefail

DRY_RUN=0
ASSUME_YES=0
WITH_GUI=0
WITHOUT_WALLET=0
WITH_ZMQ=0
WITH_IPC=0

for arg in "$@"; do
  case "$arg" in
    --dry-run) DRY_RUN=1 ;;
    --yes|-y) ASSUME_YES=1 ;;
    --with-gui) WITH_GUI=1 ;;
    --without-gui) WITH_GUI=0 ;;
    --without-wallet) WITHOUT_WALLET=1 ;;
    --with-zmq) WITH_ZMQ=1 ;;
    --with-ipc) WITH_IPC=1 ;;
    --help|-h)
      sed -n '2,12p' "$0"
      exit 0
      ;;
    *) echo "Unknown argument: $arg" >&2; exit 1 ;;
  esac
done

# --- OS detection ---
if [ -f /etc/os-release ]; then
  # shellcheck disable=SC1091
  . /etc/os-release
  OS_ID="${ID:-unknown}"
  OS_VERSION="${VERSION_ID:-}"
else
  OS_ID="unknown"
fi

pkg_manager=""
update_cmd=""
install_cmd=""

case "$OS_ID" in
  ubuntu|debian|linuxmint|pop)
    pkg_manager="apt"
    update_cmd="sudo apt-get update -qq"
    install_cmd="sudo apt-get install -y --no-install-recommends"
    ;;
  fedora|rhel|centos|rocky|almalinux)
    pkg_manager="dnf"
    update_cmd="sudo dnf check-update -q || true"
    install_cmd="sudo dnf install -y"
    ;;
  arch|manjaro|endeavouros)
    pkg_manager="pacman"
    update_cmd="sudo pacman -Sy --noconfirm"
    install_cmd="sudo pacman -S --needed --noconfirm"
    ;;
  alpine)
    pkg_manager="apk"
    update_cmd="sudo apk update"
    install_cmd="sudo apk add"
    ;;
  *)
    echo "Warning: unknown OS '$OS_ID' — trying apt as fallback." >&2
    pkg_manager="apt"
    update_cmd="sudo apt-get update -qq"
    install_cmd="sudo apt-get install -y --no-install-recommends"
    ;;
esac

# --- Package lists per distro ---
# Maps to doc/build-unix.md and doc/dependencies.md minimums.
if [ "$pkg_manager" = "apt" ]; then
  base_pkgs="build-essential cmake pkgconf python3"
  required_pkgs="libevent-dev libboost-dev"
  # Wallet (SQLite) — keep as separate so --without-wallet can skip
  wallet_pkgs="libsqlite3-dev"
  gui_pkgs="qt6-base-dev qt6-tools-dev qt6-l10n-tools qt6-tools-dev-tools libgl-dev libqrencode-dev"
  zmq_pkgs="libzmq3-dev"
  ipc_pkgs="libcapnp-dev capnproto"
elif [ "$pkg_manager" = "dnf" ]; then
  base_pkgs="gcc-c++ cmake make python3 pkgconf-pkg-config"
  required_pkgs="libevent-devel boost-devel"
  wallet_pkgs="sqlite-devel"
  gui_pkgs="qt6-qtbase-devel qt6-qttools-devel qrencode-devel"
  zmq_pkgs="zeromq-devel"
  ipc_pkgs="capnproto capnproto-devel"
elif [ "$pkg_manager" = "pacman" ]; then
  base_pkgs="base-devel cmake pkgconf python"
  required_pkgs="boost libevent"
  wallet_pkgs="sqlite"
  gui_pkgs="qt6-base qt6-tools qrencode"
  zmq_pkgs="zeromq"
  ipc_pkgs="capnproto"
elif [ "$pkg_manager" = "apk" ]; then
  base_pkgs="build-base cmake linux-headers pkgconf python3"
  required_pkgs="libevent-dev boost-dev"
  wallet_pkgs="sqlite-dev"
  gui_pkgs="qt6-qtbase-dev qt6-qttools-dev libqrencode-dev"
  zmq_pkgs="zeromq-dev"
  ipc_pkgs="capnproto capnproto-dev"
else
  base_pkgs="build-essential cmake pkgconf python3"
  required_pkgs="libevent-dev libboost-dev"
  wallet_pkgs="libsqlite3-dev"
  gui_pkgs="qt6-base-dev qt6-tools-dev libqrencode-dev"
  zmq_pkgs="libzmq3-dev"
  ipc_pkgs="libcapnp-dev capnproto"
fi

# --- Helpers to check if a package is installed ---
is_installed_apt() {
  dpkg -s "$1" >/dev/null 2>&1
}
is_installed_dnf() {
  rpm -q "$1" >/dev/null 2>&1
}
is_installed_pacman() {
  pacman -Q "$1" >/dev/null 2>&1
}
is_installed_apk() {
  apk info -e "$1" >/dev/null 2>&1
}
is_installed() {
  case "$pkg_manager" in
    apt) is_installed_apt "$1" ;;
    dnf) is_installed_dnf "$1" ;;
    pacman) is_installed_pacman "$1" ;;
    apk) is_installed_apk "$1" ;;
    *) is_installed_apt "$1" ;;
  esac
}

has_cmd() { command -v "$1" >/dev/null 2>&1; }

# --- Collect missing ---
missing=""

check_pkg_list() {
  # $1 = space-separated package list
  for pkg in $1; do
    if ! is_installed "$pkg"; then
      missing="$missing $pkg"
    fi
  done
}

# Always check base + required
check_pkg_list "$base_pkgs"
check_pkg_list "$required_pkgs"
if [ "$WITHOUT_WALLET" -eq 0 ]; then
  check_pkg_list "$wallet_pkgs"
fi
if [ "$WITH_GUI" -eq 1 ]; then
  check_pkg_list "$gui_pkgs"
fi
if [ "$WITH_ZMQ" -eq 1 ]; then
  check_pkg_list "$zmq_pkgs"
fi
if [ "$WITH_IPC" -eq 1 ]; then
  check_pkg_list "$ipc_pkgs"
fi

# Also check cmake presence via command (covers non-package cmake installs)
if ! has_cmd cmake; then
  # cmake missing even though package check may have passed on some distros
  case "$missing" in
    *cmake*) ;;
    *) missing="$missing cmake" ;;
  esac
fi

# Trim leading space
missing="$(echo "$missing" | sed 's/^ *//')"

if [ -z "$missing" ]; then
  echo "All dependencies satisfied."
  echo "Tip: for a fully self-contained build without system packages, use:"
  echo "  make -C depends -j\$(nproc) && cmake -B build --toolchain depends/x86_64-pc-linux-gnu/toolchain.cmake"
  exit 0
fi

echo "Missing packages detected ($OS_ID):"
echo "  $missing"
echo ""
if [ "$DRY_RUN" -eq 1 ]; then
  echo "[dry-run] Would run:"
  echo "  $update_cmd"
  echo "  $install_cmd $missing"
  exit 0
fi

if [ "$ASSUME_YES" -eq 0 ]; then
  printf "Install with: %s %s ? [y/N] " "$install_cmd" "$missing"
  read -r ans
  case "$ans" in
    y|Y|yes|YES) ;;
    *) echo "Aborted. Run with --yes to skip prompt, or install manually per doc/build-unix.md"; exit 1 ;;
  esac
fi

echo "Updating package lists..."
# shellcheck disable=SC2086
$update_cmd

echo "Installing: $missing"
# shellcheck disable=SC2086
$install_cmd $missing

echo "Done. You can now configure:"
echo "  cmake -B build"
echo "Or for a depends build without system packages:"
echo "  make -C depends -j\$(nproc) && cmake -B build --toolchain depends/x86_64-pc-linux-gnu/toolchain.cmake"
