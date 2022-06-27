#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n;
ll dp[MAX], p[MAX], s[MAX], a[MAX];
std::vector<ll> A;
std::vector<ll> B;

bool Bad(int l1, int l2, int l3){
	return (B[l3] - B[l1]) * (A[l1] - A[l2]) > (B[l2] - B[l1]) * (A[l1] - A[l3]);
}

void Add(ll a, ll b){ // he so tang
	A.push_back(a);
	B.push_back(b);
	while (A.size()>=3 && Bad(A.size()-3, A.size()-2, A.size()-1)){
		A.erase(A.end()-2);
		B.erase(B.end()-2);
	}
}

ll Query(ll x){ // query min
	int l = 0, r= A.size()-1;
	if (r < l) return 1e16;
	while (l < r){
		int mid = (l+r)/2;
		ll f1 = A[mid]*x + B[mid];
		ll f2 = A[mid+1]*x + B[mid+1];
		if (f1 >= f2){
			l = mid+1;
		}
		else r = mid;
	}
	return A[l]*x + B[l];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) {
		s[i] = s[i-1] + a[i]*i;
		p[i] = p[i-1] + a[i];
	}
	//dp
	Add(0,0);
	ll res = 0;
	for(int i=1; i<=n; i++){
		dp[i] = s[i] - Query(p[i]);
		Add(i, s[i] - i*p[i]);
		res = max(res, dp[i]);
	}
	cout << res;
	return 0;
}
