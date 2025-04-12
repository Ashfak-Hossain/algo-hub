#!/usr/bin/env python3
import os
import sys

if len(sys.argv) != 3:
    print("Usage: python3 create_module.py <category> <algorithm_name>")
    sys.exit(1)

category = sys.argv[1]
algo = sys.argv[2]

header_dir = os.path.join("include", *category.split("."))
test_dir = os.path.join("test", "unit", *category.split("."))

header_path = os.path.join(header_dir, f"{algo}.h")
test_path = os.path.join(test_dir, f"{algo}.test.cpp")

include_path = os.path.relpath(header_path, start=os.path.dirname(test_path))

class_name = f"Test{algo.replace('_', ' ').title().replace(' ', '')}"

# Template for the header file
header_template = f"""/**
 * author: _Berlin_
 * Description:
 * Verification:
 * Source:
**/

#pragma once

#include <>

using std::

// write your {algo} implementation here
"""

# Template for the test file
test_template = f"""#include "{include_path}"
#include "core/BerlinTestBase.h"
#include "core/BerlinTestRegister.h"

class {class_name} : public BerlinTestBase {{
public:
  {class_name}() : BerlinTestBase("{class_name}") {{}}

  void run(int id) override {{
    switch (id) {{
      case 0: check(1, 1); break; // TODO: Replace with real test
    }}
  }}

  int getCaseCount() const override {{ return 1; }}
}};

BERLIN_REGISTER_TEST({class_name});
"""

# Create directories if needed
os.makedirs(header_dir, exist_ok=True)
os.makedirs(test_dir, exist_ok=True)

# Write header file
if not os.path.exists(header_path):
    with open(header_path, "w") as f:
        f.write(header_template)
    print(f"Created: {header_path}")
else:
    print(f"Already exists: {header_path}")

# Write test file
if not os.path.exists(test_path):
    os.makedirs(os.path.dirname(test_path), exist_ok=True)
    with open(test_path, "w") as f:
        f.write(test_template)
    print(f"Created: {test_path}")
else:
    print(f"Already exists: {test_path}")
