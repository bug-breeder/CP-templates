typedef vector<ll> bigNum;

const int MOD=1e9;
bigNum a, b;
bool Neg=0;

bigNum toBig(int a)
{
    bigNum ret; ret.push_back(a); return ret;
}

bigNum Fix(bigNum &a)
{
    a.push_back(0);
    for(int i=0; i<(int)(a.size()-1); i++)
    {
        a[i+1]+=a[i]/MOD;
        a[i]%=MOD;
        while (a[i]<0) a[i+1]--, a[i]+=MOD;
    }
    while (a.size()>=2 && a.back()==0) a.pop_back();
    return a;
}

bool operator < (bigNum a, bigNum b)
{
    int SS=max(a.size(),b.size());
    a.resize(SS); b.resize(SS);
    for(int i=SS-1; i>=0; i--)
    {
        if (a[i]>b[i]) return false;
        if (a[i]<b[i]) return true;
    }
    return true;
}

bigNum operator - (bigNum a , bigNum b)
{
    if (a<b) a.swap(b), Neg=true;
    a.resize(max(a.size(),b.size()));
    REP(i,b.size()) a[i]-=b[i];
    return Fix(a);
}

bigNum operator * ( bigNum &a, bigNum &b )
{
    bigNum ret(a.size()+b.size()+2);
    REP(i,a.size())
        REP(j,b.size())
        {
            ret[i+j]+=a[i]*b[j];
            ret[i+j+1]+=(ret[i+j])/MOD;
            ret[i+j]%=MOD;
        }
    return Fix(ret);
}

void Print(bigNum a)
{
    printf("%d", a.back());
    for (int i=(int)a.size()-2; i>=0; i--)
        printf("%09d", a[i]);
}
