# Contributing to Satoxcoin Core

Satoxcoin Core is an open-source project licensed under the MIT license. Contributions are welcome.

## How to Contribute

1. **Fork** the repository on GitHub
2. **Create a branch** for your feature or fix
3. **Commit** your changes with clear, descriptive messages
4. **Push** your branch and open a Pull Request

## Development Process

- The `main` branch is the primary development branch (Satoxcoin 4.0, BTC 31.1 rebase)
- Test your changes thoroughly before submitting a PR
- Follow the existing code style and conventions
- Add comments for non-obvious logic
- Write tests for new functionality

## Code Review

- All PRs require at least one code review before merge
- Security-sensitive changes require additional review
- The project follows a review-before-merge workflow

## Building

See [doc/build-*.md](doc/build-*.md) for platform-specific build instructions, or run:

```bash
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
```

## Testing

```bash
cd build
ctest -j$(nproc)
```

Functional tests:
```bash
cd test/functional
python3 test_runner.py
```

## Links

- GitHub: https://github.com/PFORMSatox/satoxcoin
- Discord: https://discord.com/invite/GFZYFuuHVq
- Documentation: https://docs.satoverse.io

## License

By contributing to Satoxcoin Core, you agree that your contributions will be licensed under the MIT License.
