/**
 * author: _Berlin_
 * Description: A simple implementation of selection sort for sorting containers.
 * Verification: Tested with unit tests.
 * Complexity: O(n^2) time complexity, O(1) space complexity.
 * Source: own implementation.
 **/

#pragma once

#include <algorithm>

template <typename RandomIt>
void selection_sort(RandomIt begin, RandomIt end) {
  for (auto it = begin; it != end; it++) {
    auto min_it = std::min_element(it, end); 
    if (min_it != it) {
      std::iter_swap(it, min_it); 
    }
  }
}
