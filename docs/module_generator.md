# Module Generator

Quickly generate a new algorithm module along with its corresponding unit test template.

---

## Usage

```bash
python3 scripts/create_module.py <category> <module_name>
```

You can use dot notation to create nested categories:
```bash
python3 scripts/create_module.py number_theory.modular_arithmetic mod_inverse
```

---

## What This Does

This command will automatically generate:

- A header file under `include/<category>/<module_name>.h`
- A corresponding unit test file under `test/unit/<category>/<module_name>.test.cpp`

**Example:**
```bash
python3 scripts/create_module.py number_theory binpow
```

Will generate:

```
algo-hub/
├── include/
│   └── number_theory/
│       └── binpow.h
├── test/
│   └── unit/
│       └── number_theory/
│           └── binpow.test.cpp
```

---

## File Structure

Nested category support is enabled using dot `.` as separators:
```bash
python3 scripts/create_module.py math.advanced.divisors totient
```

Creates:
```
include/math/advanced/divisors/totient.h
test/unit/math/advanced/divisors/totient.test.cpp
```

---

## Generated Files

### Header File
- Template for algorithm implementation
- Author/description/verification boilerplate

### Test File
- Registered unit test class using Berlin framework
- Basic test setup for quick validation

---

## Notes

- Make the script executable:
  ```bash
  chmod +x scripts/create_module.py
  ```
- Valid identifiers only (no spaces or invalid C++ names)
- Non-existent nested folders will be created automatically

---

## Troubleshooting

- Make sure Python 3 is installed and `python3` is available
- Confirm `scripts/create_module.py` is in the correct location
- Use full nested category names using dot notation if needed

---

## Example

```bash
python3 scripts/create_module.py number_theory.modular_arithmetic mod_inverse
```

Creates:
- `include/number_theory/modular_arithmetic/mod_inverse.h`
- `test/unit/number_theory/modular_arithmetic/mod_inverse.test.cpp`

Now you're ready to implement your algorithm and write tests right away!