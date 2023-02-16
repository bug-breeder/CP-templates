ll powMod(ll x, ll k, ll M = MOD) {
    if (k==1) return x;
    if (k==0) return 1;
    ll ret = powMod(x, k/2);
    ret = (ret*ret) % M;
    if (k&1) ret = ret * x % M;
    return ret;
}
