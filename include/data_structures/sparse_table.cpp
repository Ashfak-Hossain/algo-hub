/**
 *    author:  _Berlin_
 *    Description:
 *      Static Range Query (min/max/gcd/etc) on immutable array.
 *      Precomputes answers for blocks of size 2^k at every position,
 *      enables answering any interval query in O(1) by combining 2 blocks.
 *      No updates allowed after build. Any associative, idempotent op works.
 *
 *    Usage:
 *      - table.build(array, [](int a, int b){ return min(a, b); }); // build for min
 *      - table.query(L, R); // query on [L, R] inclusive
 *      - Indices are 0-based and [L, R] is inclusive range.
 *
 *    Time Complexity:
 *      - Build: O(n log n)
 *      - Query: O(1) per query
 *
 *    Space Complexity:
 *      - O(n log n)
 */

#pragma once

#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>

struct SparseTable {
  vector<vector<int>> st;
  int n = 0, K = 0;
  function<int(int, int)> operation;

  void build(const vector<int> &a, function<int(int, int)> op) {
    n = (int)a.size();
    operation = op;
    K = n ? 32 - __builtin_clz(n) : 0;
    st.assign(K, vector<int>(n));
    copy(a.begin(), a.end(), st[0].begin());

    for (int k = 1; k < K; k++) {
      for (int i = 0; i + (1 << k) <= n; i++) {
        st[k][i] = operation(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
      }
    }
  }

  int query(int L, int R) {
    assert(L >= 0 and R < n and L <= R);
    int k = 31 - __builtin_clz(R - L + 1);
    return operation(st[k][L], st[k][R - (1 << k) + 1]);
  }
} table;