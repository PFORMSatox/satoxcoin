# Release Process

## Version Bump

Update the version in these files before each release:

```
src/clientversion.cpp    → CLIENT_VERSION_MAJOR / CLIENT_VERSION_MINOR / CLIENT_VERSION_REVISION
CMakeLists.txt           → set(CLIENT_VERSION_MAJOR ...) / set(CLIENT_VERSION_MINOR ...) / set(CLIENT_VERSION_REVISION ...)
src/kernel/chainparams.cpp → nKAAAWWWPOWActivationTime (if consensus changes)
```

Then tag the release:

```bash
git tag v<MAJOR>.<MINOR>.<REVISION>
git push origin v<MAJOR>.<MINOR>.<REVISION>
```

This triggers the GitHub Actions release workflow, which builds binaries for Linux, macOS, and Windows, and creates a GitHub Release with the artifacts.

---

## What's in a Release

### Release Checklist

- [ ] Version bumped in all locations
- [ ] `CHANGELOG.md` updated with all changes since last release
- [ ] All CI tests pass on `main`
- [ ] Manual QA testing on all platforms (Linux, macOS, Windows)
- [ ] Git tag created and pushed
- [ ] Release notes prepared
- [ ] Binaries attached to GitHub Release

### Post-Release

- [ ] Discord announcement in `#releases`
- [ ] Explorer operator notification
- [ ] P2E system team notification (if asset changes)
- [ ] Update `docs.satoverse.io` if needed

---

## Release Artifact Checksums

After the GitHub Actions release build completes, download each artifact and verify its SHA-256 checksum:

```bash
# Verify Linux tar.gz
sha256sum satoxcoin-<VERSION>-x86_64-linux.tar.gz
# Expected: <hash>  satoxcoin-<VERSION>-x86_64-linux.tar.gz

# Verify macOS universal tar.gz
sha256sum satoxcoin-<VERSION>-macos-universal.tar.gz
# Expected: <hash>  satoxcoin-<VERSION>-macos-universal.tar.gz

# Verify Windows zip
sha256sum satoxcoin-<VERSION>-win64.zip
# Expected: <hash>  satoxcoin-<VERSION>-win64.zip
```

Post the checksums in the GitHub Release body after download.

---

## Version Naming Convention

| Type | Format | Example |
|------|--------|---------|
| Major release | `vMAJOR.0.0` | `v4.0.0` |
| Minor release | `vMAJOR.MINOR.0` | `v4.1.0` |
| Patch release | `vMAJOR.MINOR.PATCH` | `v4.0.1` |
| Release candidate | `vMAJOR.0.0-rc1` | `v4.0.0-rc1` |

**Major** — consensus-affecting changes, protocol changes, hard forks
**Minor** — new features, RPC additions, performance improvements
**Patch** — bug fixes, security patches, minor improvements

---

## Consensus Version

The consensus version is determined by `CLIENT_VERSION_MAJOR` + `CLIENT_VERSION_MINOR`:

- Major bumps are **breaking** (nodes on different major versions cannot sync)
- Minor bumps are **non-breaking** (backward compatible)

Satoxcoin Core 4.0.0 is a major bump from 3.0.x — nodes running 3.0.x will not be compatible with 4.0.x nodes on mainnet.

---

## Activation Schedule

The asset-overflow BIP9 soft-fork activation follows this timeline:

| Date | Action |
|------|--------|
| Release 4.0.0 | Deployment parameters active (bit 11) |
| After release | Pools begin signaling bit 11 |
| ≥70% signal (2016 blocks) | Soft-fork locks in |
| Lock-in + 2016 blocks | Activation enforced |

Pool operators must upgrade to 4.0.0 before signaling begins. Exchange and explorer operators should upgrade before activation.

---

## Links

- **Releases:** https://github.com/PFORMSatox/satoxcoin/releases
- **Discord:** https://discord.com/invite/GFZYFuuHVq
- **Documentation:** https://docs.satoverse.io
