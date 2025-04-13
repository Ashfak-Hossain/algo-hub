/**
 * author: _Berlin_
 * Description: A unique implementation of insertion sort using iterators for flexibility.
 * Verification: Tested with unit tests.
 * Complexity: O(n^2) in the worst case, O(n) in the best case.
 * Space complexity: O(1) auxiliary space.
 * Source: own implementation.
 **/

#pragma once

#include <iterator>

template <typename RandomIt>
void insertion_sort(RandomIt begin, RandomIt end) {
  if (begin == end) return;
  for (auto it = std::next(begin); it != end; it++) {
    auto key = std::move(*it);
    auto pos = it;
    while (pos != begin && *(std::prev(pos)) > key) {
      *pos = std::move(*(std::prev(pos)));
      --pos;
    }
    *pos = std::move(key); 
  }
}