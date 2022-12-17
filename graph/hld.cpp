//problem:
//given a tree with N nodes. you have to answer 2 types of query:
// 1. Change the length i'th edge to x
// 2. What is the maximum length of an edge bewteen path from u to v
void DFS(int u) {
  c[u] = 1;
  d[u] = d[par[u]] + 1;
  int idMx = -1;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i].fi;
    if (v == par[u])
      continue;
    par[v] = u;
    DFS(v);
    c[u] += c[v];
    if (idMx == -1 || c[v] > c[g[u][idMx].fi]) {
      idMx = i;
    }
  }
  if (idMx != -1)
    swap(g[u][idMx], g[u][0]);
}

void HLD(int u, int curHead) {
  Head[u] = curHead;
  pos[u] = ++cnt;
  if (g[u][0].fi == par[u])
    return;
  Update(1,1,n,cnt+1, g[u][0].se);
  HLD(g[u][0].fi, curHead);
  for (int i = 1; i < g[u].size(); i++) {
    int v = g[u][i].fi;
    if (v == par[u])
      continue;
    Update(1,1,n,cnt+1, g[u][i].se);
    HLD(v, v);
  }
}

void Update(int id, int l, int r, int pos, int val) {
  if (l == r) {
    t[id] = val;
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid)
    Update(id * 2, l, mid, pos, val);
  else
    Update(id * 2 + 1, mid + 1, r, pos, val);
  t[id] = max(t[id * 2], t[id * 2 + 1]);
}

int ITQuery(int id, int l, int r, int u, int v) {
  if (v < l || r < u)
    return 0;
  if (u <= l && r <= v) {
    return t[id];
  }
  int mid = (l + r) / 2;
  return max(ITQuery(id * 2, l, mid, u, v),
             ITQuery(id * 2 + 1, mid + 1, r, u, v));
}

int Query(int u, int v) {
  int res = 0;
  while (Head[u] != Head[v]) {
    if (d[Head[u]] > d[Head[v]])
      swap(u, v); // v sau hon
    res = max(res, ITQuery(1, 1, n, pos[Head[v]], pos[v]));
    v = par[Head[v]];
  }
  if (pos[u] > pos[v])
    swap(u, v);
  res = max(res, ITQuery(1, 1, n, pos[u]+1, pos[v]));
  return res;
}

void Reset() {
  for(int i=1; i <=n; i++) {
    g[i].clear();
  }
  for(int i=1; i <= max(MAX-1, 4*cnt + 1); i++) {
    t[i] = 0;
  }
  cnt = 0;
}

int main (int argc, char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T; 
    while (T--){
      cin >> n;
      for(int i=1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        Edges[i] = {u,v};
      }
      DFS(1);
      HLD(1,1);
      
      while (1) {
        string Type;
        cin >> Type;
        if (Type == "DONE") break;
        if (Type == "QUERY") {
          int u, v;
          cin >> u >> v;
          cout << Query(u, v) << "\n";
        }
        else{
          int u, v;
          cin >> u >> v;
          if (d[Edges[u].fi] > d[Edges[u].se]) {
            swap(Edges[u].fi, Edges[u].se);
          }
          Update(1, 1, n, pos[Edges[u].se], v);
        }
      }
      Reset();
    }
    return 0;
}
