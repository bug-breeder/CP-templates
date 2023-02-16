long long powMod(long long x, long long k, long long M = MOD) {
    if (k==1) return x;
    if (k==0) return 1;
    ll ret = powMod(x, k/2, M);
    ret = (ret*ret) % M;
    if (k&1) ret = ret * x % M;
    return ret;
}
