#pragma once

#include <vector>
#include <algorithm>
#include <cassert>

using std::vector;

template<typename T>
vector<T> counting_sort(const vector<T>& a) {
  static_assert(std::is_integral<T>::value, "Counting sort requires integral types");
  if (a.empty()) return {}; 
  T max_val = *std::max_element(a.begin(), a.end());
  vector<size_t> countArr(static_cast<size_t>(max_val) + 1, 0);
  for (T val : a) {
    assert(val >= 0 && val <= max_val);  
    countArr[val]++;
  }
  for (size_t i = 1; i < countArr.size(); i++) {
    countArr[i] += countArr[i - 1];
  }
  vector<T> output(a.size());
  for (int i = static_cast<int>(a.size()) - 1; i >= 0; i--) {
    assert(a[i] >= 0 && a[i] <= max_val); 
    output[--countArr[a[i]]] = a[i];  
  }
  return output;
}