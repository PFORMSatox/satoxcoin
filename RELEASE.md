# Satoxcoin Core — Releases

This document defines how Satoxcoin Core versions are numbered and how a release
is cut. **This is the authoritative process.**

## Versioning

This project follows [Semantic Versioning](https://semver.org/):

```
MAJOR.MINOR.PATCH
```

- **MAJOR** — incompatible change: consensus rule change, network-protocol
  break, or a release-series reboot (e.g. the Phase 3 rebase is 3.0.0).
- **MINOR** — backwards-compatible feature addition (e.g. new RPC, new asset
  type).
- **PATCH** — backwards-compatible bug fix / security fix.

### Current baseline

- **3.0.0** — the rebased tree (Ravencoin 4.6.1 / Bitcoin Core 0.21-era base).
  This is the current `main` lineage.
- Pre-rebase (Bitcoin Core 0.15-era) ended at **2.4.1** (security maintenance).

### Where the version lives

Version is defined in **`configure.ac`** (`_CLIENT_VERSION_MAJOR/_MINOR/_REVISION`).
**Always bump it there** (the generated `satoxcoin-config.h` carries it to
`src/clientversion.cpp`).

## Consensus rule

**Consensus parameters are frozen on live mainnet.** A release that changes
consensus must:
1. Be validated against the golden manifest (`doc/security/golden-consensus-manifest.md`)
2. Pass `consensus_golden_tests`
3. Pass a mainnet sync-parity check
4. Be explicitly approved (hard-fork requires user approval and a release plan)

## Release checklist

1. **Branch** — create `release/vX.Y.Z` from `main`.
2. **Bump version** — edit `configure.ac`; commit "Bump version to X.Y.Z".
3. **Update CHANGELOG.md** — move `[Unreleased]` entries into a dated
   `[X.Y.Z]` section; open a new `[Unreleased]` section.
4. **Update security docs** — `doc/security/phase1-backports.md` and
   `doc/security/audit/cve-audit.md` verification status.
5. **Build + test** — clean build; run unit suites individually
   (golden test first, then per-suite). See `AGENTS.md`.
6. **Mainnet sync parity** — confirm tip and checkpoint hashes match the
   golden manifest.
7. **Tag** — `git tag vX.Y.Z && git push origin vX.Y.Z`.
8. **Publish** — create the GitHub release from the tag, pointing to the
   changelog entry.
9. **Announce** — satoverse.io announcements list.

## Notes on the GitHub repo

- The repository is `https://github.com/PFORMSatox/satoxcoin`; the website
  `satoverse.io` is separate and its URLs are not renamed.
- Release links must point at real artifacts only. Do not reference
  `releases/tag/vX.Y.Z` or download URLs before the tag/release exists.
- After a release, the 3.0.0 baseline (`rebase-ph3` branch) becomes `main`.
