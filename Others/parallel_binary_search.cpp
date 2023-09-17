#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

const int MAXN = 2e5 + 6;
const int MOD = 1e9 + 7;


int n, m, q;
vector<int> a;
vector<ii> queries;
vector<vector<int>> g;
vector<pair<int, vector<int>>> groups;

struct UF {
  vector<int> e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

vector<int> ans;
vector<UF> dsu(20, {MAXN});
vector<int> pt(20);

void Solve(int l, int r, int layer, vector<pair<int, vector<int>>> list) {
  if (list.empty())
    return;
  if (l == r) {
    for (auto &[id, vec] : list) {
      ans[id] = l;
    }
    return;
  }

  int mid = (l + r) / 2;
  while (pt[layer] < mid) {
    pt[layer]++;
    dsu[layer].join(queries[pt[layer]].fi, queries[pt[layer]].se);
    int u = queries[pt[layer]].fi;
    int v = queries[pt[layer]].se;
  }
  vector<pair<int, vector<int>>> l1, l2;
  for (auto &[id, vec] : list) {
    bool flag = true;
    int root = -1;
    for (auto &vertex : vec) {
      if (root == -1)
        root = vertex;
      if (!dsu[layer].sameSet(vertex, root)) {
        flag = false;
      }
    }
    if (flag) {
      l1.push_back({id, vec});
    } else {
      l2.push_back({id, vec});
    }
  }
  Solve(l, mid, layer + 1, l1);
  Solve(mid + 1, r, layer + 1, l2);
}

int main(int argc, char const *argv[]) {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
  }

  cin >> n >> m >> q;
  a.resize(n + 1);
  ans.resize(n + 2);
  g.resize(n + 2);
  queries.resize(q + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    g[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].size()) {
      vector<int> tmp;
      for (auto &x : g[i])
        tmp.push_back(x);
      groups.push_back({i, tmp});
    }
  }
  for (int i = 1; i <= q; i++) {
    int u, v;
    cin >> u >> v;
    queries[i] = {u, v};
  }
  Solve(0, q + 1, 0, groups);
  for (int i = 1; i <= m; i++) {
    if (ans[i] == q + 1)
      cout << "-1\n";
    else
      cout << ans[i] << "\n";
  }

  return 0;
}
