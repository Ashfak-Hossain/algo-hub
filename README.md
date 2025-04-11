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
./scripts/stress_test.sh <TestName>
```

### Run All Stress Tests
```bash
./scripts/stress_test.sh
```

---

## Git Pre-commit Hook – Auto Run Unit Tests

### automatically run unit tests before every git commit.
```bash
./scripts/bootstrap_hooks.sh
```
This installs a pre-commit hook into `.git/hooks/` that:
- Builds & Runs all unit_tests
- Aborts the commit if any test fails

### Skip the hook (if needed):
```bash
git commit -m "fix" --no-verify
```
### Remove the hook:
```bash
rm .git/hooks/pre-commit
```

---

## Module Generator
create a new module with header + test stub:
```bash
python3 scripts/create_module.py <category> <name>
```
Example:
```bash
python3 scripts/create_module.py number_theory binpow
```
This will create:
- `include/number_theory/binpow.h`
- `test/unit/binpow_test.cpp`