/**
 * author:  _Berlin_
 * Description:
 *  Recursive Depth-First Search (DFS) for adjacency-list graphs.
 *  Visits all nodes reachable from a given start node and marks them in 'vis'.
 *
 * Usage:
 *  1) Build adjacency lists in `g` for nodes.
 *  2) Clear visited array before each new traversal: std::fill(vis, vis + MAX_N, false).
 *  3) Call `dfs(start_node)` to visit all nodes reachable from start_node.
 *
 * Complexity:
 *  - Time:
 *      O(n + m) where n = number of nodes and m = number of edges
 *  - Space:
 *      O(n) for `vis` plus O(n + m) for adjacency lists; recursion stack is O(n) in the worst case.
 */

#pragma once

#include <vector>

using std::vector;

constexpr int MAX_N = 1e5 + 9;
vector<int> g[MAX_N];
bool vis[MAX_N];

void dfs(int u) {
  vis[u] = true;
  for (auto &v : g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

