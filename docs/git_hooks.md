# 🔁 Git Pre-commit Hook Setup

Automatically run all unit tests before committing changes.

## Install
```bash
./scripts/bootstrap_hooks.sh
```

This installs a `pre-commit` hook into `.git/hooks/` that:
- Builds & runs unit tests
- Aborts commit if any fail

## Disable Temporarily
`git commit -m "fix" --no-verify`

## Remove Hook
`rm .git/hooks/pre-commit`