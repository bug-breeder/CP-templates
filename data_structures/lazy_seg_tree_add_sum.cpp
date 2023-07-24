struct Tree {
  Tree *pl, *pr;
  int nl = 0, nr = 0, val = 0, lazy = 0;

  inline void updateVal() { val = pl->val + pr->val; }
  inline void propagate() { pl->apply(lazy), pr->apply(lazy), lazy = 0; }
  inline void apply(int x) { lazy += x, val += (nr - nl) * x; }

  Tree(int l, int r, vector<int> &A) { //[l,r)
    nl = l, nr = r;
    if (nl + 1 == nr) {
      val = A[nl];
      return;
    }
    pl = new Tree(nl, (nl + nr) >> 1, A);
    pr = new Tree((nl + nr) >> 1, nr, A);
    updateVal();
  }
  void modify(int l, int r, int x) { // add [l, r) by x
    if (l <= nl && nr <= r) {
      apply(x);
      return;
    }
    if (l >= nr || nl >= r)
      return;
    propagate();
    pl->modify(l, r, x);
    pr->modify(l, r, x);
    updateVal();
  }
  int query(int l, int r) { // sum [l, r)
    if (l <= nl && r >= nr)
      return val;
    if (l >= nr || nl >= r)
      return 0;
    propagate();
    return pl->query(l, r) + pr->query(l, r);
  }
};
