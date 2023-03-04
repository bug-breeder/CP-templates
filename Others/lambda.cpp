    function<long long(int)> fact = [&](int n) -> long long {
        if (n==1) return 1;
        return fact(n-1) * n;
    };
