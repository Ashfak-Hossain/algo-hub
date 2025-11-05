#include <bits/stdc++.h>
using namespace std;

// --- Base type printers ---
void __print(int x) {
  cerr << x;
}
void __print(long x) {
  cerr << x;
}
void __print(long long x) {
  cerr << x;
}
void __print(unsigned x) {
  cerr << x;
}
void __print(unsigned long x) {
  cerr << x;
}
void __print(unsigned long long x) {
  cerr << x;
}
void __print(float x) {
  cerr << x;
}
void __print(double x) {
  cerr << x;
}
void __print(long double x) {
  cerr << x;
}
void __print(char x) {
  cerr << '\'' << x << '\'';
}
void __print(const char *x) {
  cerr << '\"' << x << '\"';
}
void __print(const string &x) {
  cerr << '\"' << x << '\"';
}
void __print(bool x) {
  cerr << (x ? "true" : "false");
}

// --- Forward declarations ---
template <typename A> void __print(const A &);
template <typename A, typename B> void __print(const pair<A, B> &);
template <typename... A> void __print(const tuple<A...> &);
template <typename T> void __print(stack<T>);
template <typename T> void __print(queue<T>);
template <typename T, typename... U> void __print(priority_queue<T, U...>);

// --- Special array printer (for vector<int> g[N]) ---
template <typename T, size_t N> void __print(const T (&arr)[N]) {
  cerr << '{';
  bool first = true;
  for (size_t i = 0; i < N; i++) {
    if (!first) cerr << ", ";
    __print(arr[i]);
    first = false;
  }
  cerr << '}';
}

// --- Generic container printer ---
template <typename A> void __print(const A &x) {
  bool first = true;
  cerr << '{';
  for (const auto &i : x) {
    if (!first) cerr << ',';
    __print(i);
    first = false;
  }
  cerr << '}';
}

// --- Pair printer ---
template <typename A, typename B> void __print(const pair<A, B> &p) {
  cerr << '(';
  __print(p.first);
  cerr << ',';
  __print(p.second);
  cerr << ')';
}

// --- Tuple printer ---
template <typename... A> void __print(const tuple<A...> &t) {
  bool first = true;
  cerr << '(';
  apply(
      [&first](const auto &...args) {
        ((cerr << (first ? "" : ","), __print(args), first = false), ...);
      },
      t);
  cerr << ')';
}

// --- Stack printer ---
template <typename T> void __print(stack<T> s) {
  vector<T> v;
  while (!s.empty()) v.push_back(s.top()), s.pop();
  reverse(v.begin(), v.end());
  __print(v);
}

// --- Queue printer ---
template <typename T> void __print(queue<T> q) {
  vector<T> v;
  while (!q.empty()) v.push_back(q.front()), q.pop();
  __print(v);
}

// --- Priority Queue printer ---
template <typename T, typename... U> void __print(priority_queue<T, U...> q) {
  vector<T> v;
  while (!q.empty()) v.push_back(q.top()), q.pop();
  __print(v);
}

// --- Variadic print handler ---
void _print() {
  cerr << "]\n";
}

template <typename Head, typename... Tail> void _print(const Head &H, const Tail &...T) {
  __print(H);
  if (sizeof...(T)) cerr << ", ";
  _print(T...);
}

// --- Debug macro ---
#define debug(x...)                                                                                \
  cerr << "[" << #x << "] = [";                                                                    \
  _print(x)