  auto maximumMatching = [&]() -> int {
    vector<int> match(n, -1), visTime(n, -1); //0 -> n-1
    int cnt = 0;

    function<bool(int)> DFS = [&](int u) {
      if (visTime[u] == cnt)
        return false;
      visTime[u] = cnt;
      for (int v = 0; v < n; v++) {
        if (match[v] == -1 || DFS(match[v])) {
          match[v] = u;
          return true;
        }
      }
      return false;
    };

    int res = 0;
    for (cnt = 0; cnt < n; cnt++) {
      res += DFS(cnt);
    }
    return res;
  };

