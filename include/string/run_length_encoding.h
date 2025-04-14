/****
 * author:  _Berlin_
 * Description: Run-length encoding (RLE) is a simple form of data compression in which consecutive
                elements are stored as a single data value and count.
 * The time complexity of this function is O(n)
 * The space complexity is O(m), where m = unique items in the input
 * Source: https://codeforces.com/contest/2094/submission/315321306
 **/

#pragma once

#include <utility>
#include <vector>

using std::pair;
using std::vector;

template <typename T, typename T_iterable>
vector<pair<T, int>> run_length_encoding(const T_iterable &items) {
  vector<pair<T, int>> runs;
  T previous = T();
  int count = 0;
  for (const T &item : items)
    if (item == previous) {
      count++;
    } else {
      if (count > 0) {
        runs.emplace_back(previous, count);
      }
      previous = item;
      count = 1;
    }
  if (count > 0) {
    runs.emplace_back(previous, count);
  }
  return runs;
}