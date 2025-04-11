#!/bin/bash

set -e

# Get project root
PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
GIT_HOOKS_DIR="$PROJECT_ROOT/.git/hooks"
HOOK_FILE="$GIT_HOOKS_DIR/pre-commit"
UNIT_TEST_SCRIPT="$PROJECT_ROOT/scripts/unit_test.sh"

# Check if .git exists
if [ ! -d "$PROJECT_ROOT/.git" ]; then
  echo "Error: .git folder not found. Are you inside a git repo?"
  exit 1
fi

# Ensure hooks folder exists
mkdir -p "$GIT_HOOKS_DIR"

# Write hook
cat > "$HOOK_FILE" << EOF
#!/bin/bash

echo "Running unit tests before commit..."

if ! "$UNIT_TEST_SCRIPT"; then
  echo "Commit aborted: Unit tests failed!"
  exit 1
else
  echo "Unit tests passed. Proceeding with commit."
fi
EOF

# Make executable
chmod +x "$HOOK_FILE"

echo "Git pre-commit hook installed successfully!"