# Satoxcoin Core — Release Guide

## Table of Contents

- [Versioning Scheme](#versioning-scheme)
- [Quick Reference](#quick-reference)
- [Creating a Release (Automated)](#creating-a-release-automated)
- [Creating a Release (Manual)](#creating-a-release-manual)
- [Pre-Release Checklist](#pre-release-checklist)
- [Post-Release Checklist](#post-release-checklist)
- [Docker Image](#docker-image)
- [Verifying Release Artifacts](#verifying-release-artifacts)
- [Troubleshooting](#troubleshooting)

---

## Versioning Scheme

Satoxcoin Core uses **semantic versioning**: `MAJOR.MINOR.PATCH`

| Type | Format | Example | When |
|------|--------|---------|------|
| Major | `vMAJOR.0.0` | `v4.0.0` | Consensus changes, hard forks, protocol breaks |
| Minor | `vMAJOR.MINOR.0` | `v4.1.0` | New features, RPC additions, performance |
| Patch | `vMAJOR.MINOR.PATCH` | `v4.0.1` | Bug fixes, security patches |
| Release candidate | `vMAJOR.MINOR.PATCH-rcN` | `v4.0.0-rc1` | Pre-release testing |

### Version locations

Update these files before tagging a release:

| File | Variable | Purpose |
|------|----------|---------|
| `CMakeLists.txt` | `CLIENT_VERSION_MAJOR` | Major version |
| `CMakeLists.txt` | `CLIENT_VERSION_MINOR` | Minor version |
| `CMakeLists.txt` | `CLIENT_VERSION_BUILD` | Patch version |
| `CMakeLists.txt` | `CLIENT_VERSION_RC` | Release candidate (0 for final) |
| `CMakeLists.txt` | `CLIENT_VERSION_IS_RELEASE` | `"true"` for releases, `"false"` for dev |

The version string is constructed as:

```
MAJOR.MINOR.BUILD[-rcN]
```

For example: `4.0.0`, `4.1.0`, `4.0.1`, `4.0.0-rc1`

---

## Quick Reference

### Automated (GitHub Actions)

```bash
# 1. Update version in CMakeLists.txt
# 2. Commit
git commit -am "release: bump version to v4.1.0"

# 3. Tag and push
git tag v4.1.0
git push origin v4.1.0
```

The Release workflow triggers automatically on `v*` tags. It builds for Linux, macOS, Windows, and Docker, then creates a GitHub Release with all artifacts.

### Manual (local build)

```bash
# Build
cmake -B build -DCMAKE_BUILD_TYPE=Release -DENABLE_IPC=OFF
cmake --build build -j$(nproc)

# Test
cd build && ctest -j$(nproc)

# Package
VERSION="4.1.0"
cd build
tar czf ../satoxcoin-${VERSION}-x86_64-linux.tar.gz \
  bin/satoxcoind bin/satoxcoin-cli bin/satoxcoin-tx bin/satoxcoin-wallet
```

---

## Creating a Release (Automated)

The GitHub Actions Release workflow (`.github/workflows/release.yml`) handles everything when you push a `v*` tag.

### What it does

1. **Builds binaries** on 3 platforms in parallel:
   - Linux x86_64 (Ubuntu 24.04)
   - macOS Universal (arm64 + x86_64)
   - Windows x86_64 (Windows Server 2022)
2. **Runs unit tests** on the Linux build
3. **Builds Docker image** and pushes to `ghcr.io`
4. **Creates GitHub Release** with all binaries attached

### Step-by-step

#### 1. Ensure all CI checks pass

```bash
# Verify main branch is green
gh api repos/PFORMSatox/satoxcoin/actions/runs --jq '.workflow_runs[0].conclusion'
# Should show: "success"
```

#### 2. Update version numbers

Edit `CMakeLists.txt`:

```cmake
set(CLIENT_VERSION_MAJOR 4)
set(CLIENT_VERSION_MINOR 1)
set(CLIENT_VERSION_BUILD 0)
set(CLIENT_VERSION_RC 0)          # 0 for final release, 1+ for RC
set(CLIENT_VERSION_IS_RELEASE "true")
```

#### 3. Write release notes

Update `doc/release-notes.md` with changes for this version. Archive the previous version's notes:

```bash
cp doc/release-notes.md doc/release-notes/release-notes-OLDVERSION.md
```

#### 4. Commit and tag

```bash
git add -A
git commit -m "release: bump version to v4.1.0"
git tag -s v4.1.0 -m "Satoxcoin Core v4.1.0"
git push origin main
git push origin v4.1.0
```

#### 5. Monitor the build

```bash
# Watch the workflow
gh run watch
```

Or check: https://github.com/PFORMSatox/satoxcoin/actions/workflows/release.yml

#### 6. Verify the release

Once the workflow completes:

```bash
# Check release exists
gh release view v4.1.0

# Download and verify checksums
gh release download v4.1.0
sha256sum satoxcoin-*
```

### Docker image

The workflow pushes to GitHub Container Registry:

```bash
# Pull
docker pull ghcr.io/pformsatox/satoxcoin/satoxcoind:v4.1.0

# Run
docker run -v satoxcoin_data:/var/lib/satoxcoin \
  ghcr.io/pformsatox/satoxcoin/satoxcoind:v4.1.0
```

Docker tags created automatically:
- `v4.1.0` — exact version
- `4.1` — major.minor
- `latest` — most recent release

---

## Creating a Release (Manual)

Use this when you need to build locally (e.g., for codesigning or custom builds).

### Prerequisites

| Platform | Dependencies |
|----------|-------------|
| Linux | `cmake`, `g++`, `libboost-dev`, `libevent-dev`, `libsqlite3-dev` |
| macOS | `cmake`, `boost`, `libevent`, `sqlite` (via Homebrew) |
| Windows | `cmake`, `vcpkg` with `boost`, `libevent`, `sqlite3` |

### Linux build

```bash
cmake -B build \
  -DCMAKE_BUILD_TYPE=Release \
  -DENABLE_IPC=OFF \
  -DBUILD_SATOXCOIN_CLI=ON \
  -DBUILD_SATOXCOIN_TX=ON \
  -DBUILD_SATOXCOIN_UTIL=ON \
  -DENABLE_WALLET=ON

cmake --build build -j$(nproc)
cd build && ctest -j$(nproc)
```

### macOS build (universal binary)

```bash
cmake -B build \
  -DCMAKE_BUILD_TYPE=Release \
  -DENABLE_IPC=OFF \
  -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64"

cmake --build build -j$(sysctl -n hw.ncpu)
```

### Windows build

```bash
vcpkg integrate install
vcpkg install boost libevent sqlite3 --triplet x64-windows

cmake -B build \
  -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake \
  -DVCPKG_TARGET_TRIPLET=x64-windows \
  -DCMAKE_BUILD_TYPE=Release \
  -DENABLE_IPC=OFF

cmake --build build --config Release -j 4
```

### Package the release

```bash
VERSION="4.1.0"

# Linux
cd build && tar czf ../satoxcoin-${VERSION}-x86_64-linux.tar.gz \
  bin/satoxcoind bin/satoxcoin-cli bin/satoxcoin-tx bin/satoxcoin-wallet

# macOS
tar czf satoxcoin-${VERSION}-macos-universal.tar.gz \
  bin/satoxcoind bin/satoxcoin-cli bin/satoxcoin-tx bin/satoxcoin-wallet

# Windows (PowerShell)
Compress-Archive -Path build/bin/Release/satoxcoind.exe,build/bin/Release/satoxcoin-cli.exe,build/bin/Release/satoxcoin-tx.exe,build/bin/Release/satoxcoin-wallet.exe \
  -DestinationPath "satoxcoin-${VERSION}-win64.zip"
```

### Create the GitHub Release manually

```bash
gh release create v4.1.0 \
  --title "Satoxcoin Core v4.1.0" \
  --notes-file release-notes.md \
  satoxcoin-${VERSION}-x86_64-linux.tar.gz \
  satoxcoin-${VERSION}-macos-universal.tar.gz \
  satoxcoin-${VERSION}-win64.zip
```

### Build Docker image manually

```bash
docker build -t satoxcoind:v${VERSION} .
docker tag satoxcoind:v${VERSION} ghcr.io/pformsatox/satoxcoin/satoxcoind:v${VERSION}
docker push ghcr.io/pformsatox/satoxcoin/satoxcoind:v${VERSION}
```

---

## Pre-Release Checklist

### Code

- [ ] All CI checks pass on `main` (build, lint, unit tests)
- [ ] Version bumped in `CMakeLists.txt` (`CLIENT_VERSION_MAJOR`, `MINOR`, `BUILD`, `RC`)
- [ ] `CLIENT_VERSION_IS_RELEASE` set to `"true"`
- [ ] No known regressions from previous release
- [ ] Security fixes reviewed and tested

### Documentation

- [ ] `doc/release-notes.md` updated with all notable changes
- [ ] Previous release notes archived to `doc/release-notes/release-notes-OLDVERSION.md`
- [ ] Man pages regenerated (if RPC changes): `contrib/devtools/gen-manpages.py`
- [ ] Build documentation updated (`doc/build-*.md`) if build process changed

### Testing

- [ ] Unit tests pass: `cd build && ctest -j$(nproc)`
- [ ] Functional tests pass: `cd test/functional && python3 test_runner.py`
- [ ] Manual QA: send transaction, list assets, create/reissue asset
- [ ] Test on all 3 platforms (Linux, macOS, Windows)
- [ ] Docker image builds and runs correctly

### Tagging

- [ ] Tag is signed: `git tag -s v<VERSION> -m "Satoxcoin Core <VERSION>"`
- [ ] Tag format matches: `vMAJOR.MINOR.PATCH` (e.g., `v4.1.0`)
- [ ] Tag pushed to origin: `git push origin v<VERSION>`

---

## Post-Release Checklist

### Immediate

- [ ] GitHub Release created with all binaries attached
- [ ] SHA-256 checksums posted in release notes
- [ ] Docker image pushed to `ghcr.io`
- [ ] Release notes published on GitHub

### Community

- [ ] Announcement in Discord `#releases` channel
- [ ] Explorer operator notification (if consensus/protocol changes)
- [ ] P2E system team notification (if asset changes)
- [ ] Update `docs.satoverse.io` if needed

### Infrastructure

- [ ] Pool operators notified (if consensus changes)
- [ ] Exchange operators notified (if wallet/RPC changes)
- [ ] Checkpoint data updated in `src/chainparams.cpp` (if needed)

---

## Docker Image

### Available images

| Tag | Description |
|-----|-------------|
| `ghcr.io/pformsatox/satoxcoin/satoxcoind:latest` | Most recent release |
| `ghcr.io/pformsatox/satoxcoin/satoxcoind:v4.1.0` | Specific version |
| `ghcr.io/pformsatox/satoxcoin/satoxcoind:4.1` | Major.minor |

### Running

```bash
# Basic
docker run -d \
  -v satoxcoin_data:/var/lib/satoxcoin \
  -p 18333:18333 \
  ghcr.io/pformsatox/satoxcoin/satoxcoind:latest

# With custom config
docker run -d \
  -v satoxcoin_data:/var/lib/satoxcoin \
  -v satoxcoin.conf:/var/lib/satoxcoin/satoxcoin.conf \
  -p 18333:18333 \
  ghcr.io/pformsatox/satoxcoin/satoxcoind:latest
```

### Exposed ports

| Port | Protocol | Purpose |
|------|----------|---------|
| 18333 | TCP | P2P network |
| 60777 | TCP | RPC (if configured) |

---

## Verifying Release Artifacts

### Checksums

After downloading artifacts from the GitHub Release:

```bash
# Linux
sha256sum satoxcoin-4.1.0-x86_64-linux.tar.gz
# Expected: <hash>  satoxcoin-4.1.0-x86_64-linux.tar.gz

# macOS
sha256sum satoxcoin-4.1.0-macos-universal.tar.gz
# Expected: <hash>  satoxcoin-4.1.0-macos-universal.tar.gz

# Windows
sha256sum satoxcoin-4.1.0-win64.zip
# Expected: <hash>  satoxcoin-4.1.0-win64.zip
```

### Binary verification

```bash
# Extract and check version
tar xzf satoxcoin-4.1.0-x86_64-linux.tar.gz
./bin/satoxcoind --version
# Should output: Satoxcoin Core version v4.1.0
```

---

## Troubleshooting

### Tag pushed but workflow didn't trigger

- Ensure the tag matches `v*` pattern (e.g., `v4.1.0`, not `4.1.0`)
- Check the Actions tab: https://github.com/PFORMSatox/satoxcoin/actions/workflows/release.yml
- Re-trigger by deleting and re-pushing the tag:
  ```bash
  git tag -d v4.1.0
  git push origin :refs/tags/v4.1.0
  git tag -s v4.1.0 -m "Satoxcoin Core v4.1.0"
  git push origin v4.1.0
  ```

### Build fails on one platform

- Check the specific job logs in the Actions tab
- Linux failures are usually missing dependencies
- macOS failures may be SDK or architecture-related
- Windows failures may be vcpkg or PowerShell-related

### Docker push fails

- Ensure `GITHUB_TOKEN` has `packages: write` permission
- Check that the workflow has `permissions.packages: write` in the `docker-build` job
- Verify the image name matches: `ghcr.io/${{ github.repository }}/satoxcoind`

### Wrong version in binary

- Verify `CMakeLists.txt` has the correct version numbers
- Ensure `CLIENT_VERSION_RC` is `0` for final releases
- Check that the tag was created after the version bump commit
