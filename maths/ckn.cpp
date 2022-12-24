ll power(ll x, ll k) {
    if (k==1) return x;
    if (k==0) return 1;
    ll ret = power(x, k/2);
    ret = (ret*ret) % MOD;
    if (k&1) ret = ret * x % MOD;
    return ret;
}
 
ll C(ll k, ll n) {
    if (k==0) return 1;
    if (k > n) return 0;
    if (k < 0) return 0;
    return fac[n] * power(fac[k], MOD-2) % MOD * power(fac[n-k], MOD-2) % MOD; 
}
//fac[0] = 1;
//FOR(i,1,MAX-1) fac[i] = (fac[i-1]*i) % MOD;
