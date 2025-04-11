# algo-hub – Competitive Programming Toolkit

---

## Structure

| Folder           | Description                               |
|------------------|-------------------------------------------|
| `include/`       | All algorithm headers (modular, reusable) |
| `test/core/`     | Test framework (Berlin-style)             |
| `test/unit/`     | Functional unit tests                     |
| `test/stress/`   | Stress & randomized tests                 |
| `test/main.cpp`  | Shared test runner                        |
| `scripts/`       | Automation scripts (build/run/generate)   |
| `docs/`          | Internal documentation                    |
| `debug/`         | Debug file for cp                         |
| `CMakeLists.txt` | Config for building everything with CMake |

---

## Usage Testing

### Run a Specific Unit Test

```bash
./scripts/unit_test.sh <TestName>
./scripts/unit_test.sh TestBinpow
```

### Run All Unit Tests

```bash
./scripts/unit_test.sh
```

### Run a Specific Stress Test

```bash 
./scripts/stress_test.sh TestStress
```

### Run All Stress Tests

```bash
./scripts/stress_test.sh
```

---
