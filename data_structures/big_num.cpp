#include <bits/stdc++.h>
using namespace std;

struct bigNum
{
    //Chua su ly duoc so am
    vector<long long> Data;
    static const int MOD = 1e9;

    bigNum(int a = 0){
        Data.push_back(a);
    }

    bigNum(const bigNum &a){
        this->Data = a.Data;
    }

    void Fix()
    {
        Data.push_back(0);
        for(int i=0; i<(int)(Data.size()-1); i++)
        {
            Data[i+1]+Data[i]/MOD;
            Data[i]%=MOD;
            while (Data[i]<0) Data[i+1]--, Data[i]+=MOD;
        }
        while (Data.size()>=2 && Data.back()==0) Data.pop_back();
    }

    bool operator < (bigNum &b)
    {
        int SS=max(Data.size(),b.Data.size());
        Data.resize(SS); b.Data.resize(SS);
        for(int i=SS-1; i>=0; i--)
        {
            if (Data[i]>b.Data[i]) return false;
            if (Data[i]<b.Data[i]) return true;
        }
        return true;
    }

    bigNum operator - (const bigNum &b)
    {

        bigNum res(*this);
        res.Data.resize(max(res.Data.size(),b.Data.size()));
        for(int i=0; i < b.Data.size(); i++) res.Data[i]-=b.Data[i];
        res.Fix();
        return res;
    }

    bigNum operator + (const bigNum &b)
    {
        bigNum res(*this);
        res.Data.resize(max(res.Data.size(),b.Data.size()));
        for(int i=0; i<(int)b.Data.size(); i++) res.Data[i]+=b.Data[i];
        res.Fix();
        return res;
    }

    bigNum operator * (const bigNum &b )
    {
        bigNum res;
        res.Data.resize(Data.size()+b.Data.size()+2);
        for(int i=0; i < (int)Data.size(); i++)
            for(int j=0; j < (int)b.Data.size(); j++)
            {
                res.Data[i+j]+=Data[i]*b.Data[j];
                res.Data[i+j+1]+=(res.Data[i+j])/MOD;
                res.Data[i+j]%=MOD;
            }
        res.Fix();
        return res;
    }

    void Print()
    {
        printf("%d", Data.back());
        for (int i=(int)Data.size()-2; i>=0; i--)
            printf("%09d", Data[i]);
    }
};

int main(){
    int x, y;
    cin >> x >> y;
    bigNum a(x), b(y);
    for(int i = 2; i<=y; i++){
        bigNum tmp(x);
        a = a*tmp;
    }    
    for(int i = 2; i<=x; i++){
        bigNum tmp(y);
        b = b*tmp;
    }    
    bigNum tmp = a<b?b-a:a-b;
    if (a < b) cout << "-";
    tmp.Print();
    return 0;
}