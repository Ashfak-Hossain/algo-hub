# algo-hub – Competitive Programming Toolkit
![C++](https://img.shields.io/badge/language-C++-blue)
![Build](https://img.shields.io/badge/build-passing-brightgreen)

---

A structured C++ algorithm library for competitive programming with testing, modular headers, and automation tools.

---

## Structure

| Folder           | Description                               |
|------------------|-------------------------------------------|
| `include/`       | All algorithm headers (modular, reusable) |
| `test/core/`     | Test framework (Berlin-style)             |
| `test/unit/`     | Functional unit tests                     |
| `test/stress/`   | Stress & randomized tests                 |
| `scripts/`       | Automation scripts (build/run/generate)   |
| `docs/`          | Internal documentation                    |
| `debug/`         | CP-specific debug helpers                 |
| `CMakeLists.txt` | CMake build setup                         |

---

## Docs

- [Unit & Stress Testing Guide](docs/usage_tests.md)
- [Git Pre-commit Hook Setup](docs/git_hooks.md)
- [Create New Module](docs/module_generator.md)

---

## Quick Start

```bash
# Run all unit tests
./scripts/unit_test.sh
# Create a new module + test
python3 scripts/create_module.py number_theory binpow
````