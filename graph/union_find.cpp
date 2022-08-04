int Find(int x){
	if (x==par[x]) return x;
	return par[x] = Find(par[x]);
}
 
bool Union(int a, int b){
	int x = Find(a), y = Find(b);
	if (x==y) return false;
	if (x > y) swap(x, y);
	par[y] = x;
	return true;
}
 
