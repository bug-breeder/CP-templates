ll power(ll x, ll k) {
    if (k==1) return x;
    if (k==0) return 1;
    ll ret = power(x, k/2);
    ret = (ret*ret) % MOD;
    if (k&1) ret = ret * x % MOD;
    return ret;
}
