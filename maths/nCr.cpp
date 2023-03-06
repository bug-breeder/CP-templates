long long powMod(long long x, long long k) {
    if (k==1) return x;
    if (k==0) return 1;
    long long ret = powMod(x, k/2);
    ret = (ret*ret) % MOD;
    if (k&1) ret = ret * x % MOD;
    return ret;
}
 
long long C(long long k, long long n) {
    if (k==0) return 1;
    if (k > n) return 0;
    if (k < 0) return 0;
    return fac[n] * powMod(fac[k], MOD-2) % MOD * powMod(fac[n-k], MOD-2) % MOD; //use invFac to get faster
}
//fac[0] = 1;
//FOR(i,1,MAX-1) fac[i] = (fac[i-1]*i) % MOD;