/**
 * author: _Berlin_
 * Description: A recursive implementation of quick sort using a pivot for partitioning.
 * Verification: Tested with unit tests.
 * Complexity: O(n log n) on average, O(n^2) in the worst case.
 * Space Complexity: O(log n) for recursion stack.
 * Source: own implementation.
 **/

#pragma once

#include <iterator>
#include <algorithm>

template <typename RandomIt>
RandomIt partition(RandomIt begin, RandomIt end) {
    auto pivot = std::prev(end); 
    auto i = begin;

    for (auto j = begin; j != pivot; j++) {
      if (*j <= *pivot) {
        std::iter_swap(i, j);
        i++;
      }
    }
    std::iter_swap(i, pivot); 
    return i;
}

template <typename RandomIt>
void quick_sort(RandomIt begin, RandomIt end) {
  if (std::distance(begin, end) <= 1) return;
  auto pivot = partition(begin, end); 
  quick_sort(begin, pivot);           
  quick_sort(std::next(pivot), end);
}
