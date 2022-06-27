#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define ll long long
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;
 
const int MAX = 2e5+6;
const int MOD = 1e9+7;

ll t[MAX*4], id[MAX*4], m, n;
ll a[MAX], Lazy[MAX*4];
 
void Down(int id){
	t[id*2]+= Lazy[id];
	t[id*2+1]+= Lazy[id];
	Lazy[id*2]+= Lazy[id];
	Lazy[id*2+1]+= Lazy[id];
	Lazy[id] = 0;
}
 
void Build(int id, int l, int r){
	if (l==r){
		t[id] = a[l];
		return;
	}
	int mid = (l+r)/2;
	Build(id*2, l, mid);
	Build(id*2+1, mid+1, r);
}
 
void Update(int id, int l, int r, int L, int R, int val){
	if (r<L || R<l) return;
	if (L<=l && r<=R){
		Lazy[id] += val;
		if (l==r) t[id]+= val;
		return;
	}
	Down(id);
	int mid = (l+r)/2;
	Update(id*2, l, mid, L, R, val);
	Update(id*2+1, mid+1, r, L, R, val);
}
 
ll Query(int id, int l, int r, int pos){
	if (l==r && r==pos){
		return t[id];
	}
	Down(id);
	int mid = (l+r)/2;
	if (pos <= mid) return Query(id*2, l, mid, pos);
	else return Query(id*2+1, mid+1, r, pos);
}
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif
 
	cin >> n >> m;
	FOR(i,1,n) cin >> a[i];
	Build(1,1,n);
	FOR(i,1,m){
		int Type, a, b, u, k;
		cin >> Type;
		if (Type==1){
			cin >> a >> b >> u;
			Update(1,1,n,a,b,u);
		}
		else{
			cin >> k;
			cout << Query(1,1,n,k) << "\n";
		}
	}	
	Update(1,1,n,8,8,10);
	return 0;
}
