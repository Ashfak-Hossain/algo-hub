/**
 * author: _Berlin_
 * Description: Bubble Sort
 * Verification: Verified with unit tests on various integer vectors
 * Source: own
**/

#pragma once

#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

template <typename T>
void bubble_sort(vector<T>& v) {
  int n = static_cast<int>(v.size());
  for (int i = n - 1; i >= 0; i--) {
    bool didSwap = false;
    for (int j = 0; j < i; j++) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
        didSwap = true;
      }
    }
    if (!didSwap) break;
  }
}