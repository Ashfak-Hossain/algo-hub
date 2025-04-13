/**
 * author: _Berlin_
 * Description: A non-comparison-based sorting algorithm for integers.
 * Verification: Tested with unit tests.
 * Complexity: O(n + k) time complexity, where k is the range of input values.
 * Space Complexity: O(n + k) auxiliary space.
 * Source: own implementation.
 **/

#pragma once

#include <vector>
#include <cassert>

template <typename T>
void counting_sort(std::vector<T>& arr, T min_val, T max_val) {
  static_assert(std::is_integral<T>::value, "Counting sort requires integral types");
  assert(min_val <= max_val);
  std::vector<size_t> count(max_val - min_val + 1, 0);
  for (const auto& val : arr) {
    count[val - min_val]++;
  }
  size_t index = 0;
  for (T i = min_val; i <= max_val; i++) {
    while (count[i - min_val] > 0) {
      arr[index++] = i;
      count[i - min_val]--;
    }
  }
}