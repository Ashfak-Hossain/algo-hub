# Unit & Stress Testing Guide

This guide explains how to use the unit and stress testing utilities in the `algo-hub` project.

---

## Unit Tests

### List All Available Unit Tests

```bash
make list_tests
# or
./scripts/unit_test.sh --list
```

### Run a Specific Unit Test

```bash
make run_utest TEST_NAME=TestBinpow
# or
./scripts/unit_test.sh TestBinpow
```

### Clean, Build, and Run All Unit Tests

```bash
make unit_tests
# or
./scripts/unit_test.sh
```

---

## Stress Tests

### Run a Specific Stress Test

```bash
make run_stress TEST_NAME=TestFooStress
# or
./scripts/stress_test.sh TestFooStress
```

### Run All Stress Tests

```bash
make stress_tests
# or
./scripts/stress_test.sh
```

---

## Notes

- `TEST_NAME` is case-sensitive and should match the test class name registered via `BERLIN_REGISTER_TEST(...)`.
- Scripts auto-build if necessary before running tests.
- Use `make rebuild` to force a clean build.