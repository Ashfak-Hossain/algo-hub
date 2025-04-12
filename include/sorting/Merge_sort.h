/**
 * author: _Berlin_
 * Description: A recursive implementation of merge sort for sorting containers with random-access iterators.
 * Verification: Tested with unit tests.
 * Complexity: O(n log n) time complexity, O(n) auxiliary space.
 * Source: own implementation.
 **/

#pragma once

#include <vector>
#include <iterator>
#include <algorithm>

using std::vector;

template <typename RandomIt>
void merge(RandomIt begin, RandomIt mid, RandomIt end) {
    using ValueType = typename std::iterator_traits<RandomIt>::value_type;
    vector<ValueType> left(begin, mid);
    vector<ValueType> right(mid, end);

    auto leftIt = left.begin();
    auto rightIt = right.begin();
    auto destIt = begin;

    while (leftIt != left.end() && rightIt != right.end()) {
      if (*leftIt <= *rightIt) {
        *destIt++ = std::move(*leftIt++);
      } else {
        *destIt++ = std::move(*rightIt++);
      }
    }

    // Copy remaining elements
    std::move(leftIt, left.end(), destIt);
    std::move(rightIt, right.end(), destIt);
}

template <typename RandomIt>
void merge_sort(RandomIt begin, RandomIt end) {
    auto size = std::distance(begin, end);
    if (size <= 1) return;

    auto mid = std::next(begin, size / 2);
    merge_sort(begin, mid);
    merge_sort(mid, end);
    merge(begin, mid, end);
}
