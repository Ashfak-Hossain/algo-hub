#!/usr/bin/env python3
import os
import sys

if len(sys.argv) != 3:
    print("Usage: python3 create_module.py <category> <algorithm_name>")
    sys.exit(1)

category = sys.argv[1]
algo = sys.argv[2]
header_dir = f"include/{category}"
test_dir = "test/unit"
header_path = f"{header_dir}/{algo}.h"
test_path = f"{test_dir}/{algo}.test.cpp"
class_name = f"Test{algo.capitalize()}"

# Template for the header file
header_template = f"""
/**
 * author: _Berlin_
 * Description: {algo} implementation
**/

#pragma once

#include <bits/stdc++.h>
using namespace std;

// write your {algo} implementation here
"""

# Template for the test file
test_template = f"""
#include "../../include/{category}/{algo}.h"
#include "../core/BerlinTestBase.h"
#include "../core/BerlinTestRegister.h"

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

# Create header and test directories if needed
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
    with open(test_path, "w") as f:
        f.write(test_template)
    print(f"Created: {test_path}")
else:
    print(f"Already exists: {test_path}")