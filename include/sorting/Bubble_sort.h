/**
 * author: _Berlin_
 * Description: A simple implementation of bubble sort for sorting containers with random-access iterators.
 * Verification: Tested with unit tests.
 * Complexity: O(n^2) time complexity, O(1) space complexity.
 * Source: own implementation.
 **/

#pragma once

#include <iterator>
#include <algorithm>

template <typename RandomIt>
void bubble_sort(RandomIt begin, RandomIt end) {
  if (begin == end) return;

  for (auto i = begin; i != end; i++) {
    bool swapped = false;
    for (auto j = begin; std::next(j) != end - std::distance(begin, i); j++) {
      if (*j > *std::next(j)) {
        std::iter_swap(j, std::next(j));
        swapped = true;
      }
    }
    if (!swapped) break;
  }
}