# Security Policy

## Supported Versions

| Version | Supported |
|---------|-----------|
| 4.0.x (BTC 31.1 rebase) | ✅ Active |
| 3.0.x | ⚠️ Maintenance only — upgrade to 4.0 recommended |
| 2.x | ❌ Not supported |

## Reporting a Vulnerability

Please report security issues **privately** — do **not** open a public GitHub issue.

### Primary: GitHub Private Vulnerability Reporting

Use [GitHub's private vulnerability reporting](https://github.com/PFORMSatox/satoxcoin/security/advisories/new) to submit a report. This is the preferred channel — reports are private and encrypted.

### Alternative: Discord

DM a Satoxcoin Core team member on our [Discord](https://discord.com/invite/GFZYFuuHVq) (use the `#security-disclosure` channel).

### What to include

- Description of the vulnerability
- Steps to reproduce (if applicable)
- Potential impact
- Suggested fix (if you have one)

We will respond within 72 hours and work with you to coordinate disclosure.

## Security Fixes in 4.0

The 4.0 rebase (BTC 31.1 base) includes fixes for all known CVEs through v31.1:

- **KAWPOW hardening**: mix_hash forgery, nHeight forgery, epoch-DoS
- **Asset system hardening**: ConnectBlock/DisconnectBlock non-fatal asset failures, reissue overflow, flush corruption
- **BTC 31.1 base**: 16 CVEs natively fixed including script interpreter UAF, compact block stall, headers-spam OOM, log flood DoS, and more

See `doc/security/audit/cve-audit.md` for the full CVE audit.
