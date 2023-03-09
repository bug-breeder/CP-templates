struct FenwickTree {
  vector<long long> s;
  int tree_size;

  inline void update(long long &target, long long &value) { target += value; }

  FenwickTree(int tree_size = 0, int val = 0) : tree_size(tree_size) {
    s.resize(tree_size, val);
  }
  void update(int pos, long long val) { // s[pos]+= val
    for (; pos < tree_size; pos += pos & -pos)
      update(s[pos], val);
  }
  long long query(int pos) { // [1, pos]
    long long ret = 0;
    for (; pos > 0; pos -= pos & -pos)
      update(ret, s[pos]);
    return ret;
  }
};
