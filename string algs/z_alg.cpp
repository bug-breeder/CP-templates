#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
string s;
std::vector<int> z;
 
int main(int argc, char const *argv[])
{
	cin >> s;
	int n = s.size();
	z.resize(n,0);//mang Z
 
	z[0] = n;
	int l =0, r= 0 ;
	for(int i=1; i<n; i++){
		int x = max(0, min(r-i+1, z[i-l]));
		while (i+x < n && s[x] == s[i+x]) x++;
		z[i] = x;
		if (x + i -1> r){
			l = i;
			r = i + x -1;
		}
	}
    // danh so tu 0
}
