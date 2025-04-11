# Module Generator

Quickly generate a new algorithm + unit test template.

## Usage
```bash
python3 scripts/create_module.py <category> <name>

Example:
python3 scripts/create_module.py number_theory binpow
```

This creates:
- include/number_theory/binpow.h
- test/unit/binpow.test.cpp