/**
 *    author:  _Berlin_
 *    Description:
 *      Standard Segment Tree for static/dynamic range queries (sum, min, max).
 *      Supports Point updates and query on intervals.
 *
 *    Usage:
 *      - tree.build(1, 0, n - 1);      // build with initial array `a[0...n-1]`
 *      - tree.update(1, 0, n - 1, idx, x); // update a[idx] to x
 *      - tree.query(1, 0, n - 1, l, r); // query [l, r] inclusive
 *
 *    Time Complexity:
 *      - Build: O(n)
 *      - Point Update: O(log n)
 *      - Query: O(log n) per query
 *
 *    Space Complexity:
 *      - O(4*n) (safe upper bound for tree's array)
 *
 *    Constraints & Limitations:
 *      - Operates on static array with dynamic queries/updates
 *      - Indices are 0-based in the array; functions use [b,e] segment
 *
 *    Memorization Note:
 *      - Each node stores answer for [b,e] interval
 *      - Children: lc = left child, rc = right child
 *      - Build recursively, update point, query interval by splitting
 *      - Inf value (`-inf`/`inf`) must suit the op (0 for sum, INT_MAX for min)
 *      - Typical ops: sum, min, max (set in combine & pull)
 *
 *     Source: YouKnowWho
 */

#pragma once

#include <cstring>

const int N = 1e5 + 5;

int a[N];
struct Segtree {
#define lc (n << 1)
#define rc ((n << 1) + 1)
  int t[N << 2];
  static const int inf = 0x3f3f3f3f;

  Segtree() { memset(t, 0, sizeof t); }

  inline int combine(int a, int b) { return a + b; }

  inline void pull(int n) { t[n] = t[lc] + t[rc]; }

  void build(int n, int b, int e) {
    if (b == e) {
      t[n] = a[b]; // set value
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }

  void update(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      t[n] = x;
      return;
    }
    int mid = (b + e) >> 1;
    update(lc, b, mid, i, x);
    update(rc, mid + 1, e, i, x);
    pull(n);
  }

  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return -inf; // return appropriate value
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
} tree;