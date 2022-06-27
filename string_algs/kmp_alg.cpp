#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
string s, t;
int p[2000005];
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> s;
	cin >> t;
	s= '#' + t + "#" + s;
	//kmp, danh so tu 1
	int k = 0;
	for(int i=2; i<(int)s.size(); i++){
		while (k && s[i]!= s[k+1]) k = p[k];
		if (s[i] == s[k+1]) k++;
		p[i] = k;
	}
	//dem so lan xuat hien cua xau t trong xau s
	int res = 0;
	for(int i=1; i<(int) s.size(); i++){
		if (p[i] == (int)t.size()) res++;
	}
	cout << res;
	return 0;
}
