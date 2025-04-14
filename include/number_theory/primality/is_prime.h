/**
  * author:  _Berlin_
  * Description: A function to check if a number is prime using trial division.
  * Time Complexity: O(sqrt(n)) for each query.
  * Space Complexity: O(1).
  * Usage: is_prime(n) returns true if n is prime, false otherwise.
  * Verification: Tested with unit tests.
  * Source: own implementation.
 **/

#pragma once

#include <type_traits>
#include <cassert>

template<typename T>
constexpr bool is_prime(T n) {
  assert(std::is_integral_v<T>);
  if (n <= 3) return n > 1;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (T i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
