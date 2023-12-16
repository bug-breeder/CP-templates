 
static char buf[450 << 20];
void *operator new(size_t s) {
  static size_t i = sizeof buf;
  assert(s < i);
  return (void *)&buf[i -= s];
}
void operator delete(void *) {}
 
const int inf = 1e9;
struct Node {
  Node *l = 0, *r = 0;
  int lo, hi, mset = inf, madd = 0, val = -inf;
  Node(int lo, int hi) : lo(lo), hi(hi) {} // Large interval of -inf
  Node(vi &v, int lo, int hi) : lo(lo), hi(hi) {
    if (lo + 1 < hi) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      val = (l->val + r->val);
    } else
      val = v[lo];
  }
  int query(int L, int R) {
    if (R <= lo || hi <= L)
      return 0;
    if (L <= lo && hi <= R)
      return val;
    push();
    return (l->query(L, R) + r->query(L, R));
  }
  void set(int L, int R, int x) {
    if (R <= lo || hi <= L)
      return;
    if (L <= lo && hi <= R) {
      mset = x, madd = 0;
      val = (hi - lo) * mset;
    } else {
      push(), l->set(L, R, x), r->set(L, R, x);
      val = (l->val + r->val);
    }
  }
  void push() {
    if (!l) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (mset != inf)
      l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
  }
};
//[l, r+1] for query and set
