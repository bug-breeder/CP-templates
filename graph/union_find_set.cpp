int Find(int x){
	if (x==par[x]) return x;
	return par[x] = Find(par[x]);
}
 
bool Union(int a, int b){
	int x = Find(a), y = Find(b);
	if (x==y) return false;
	if (S[x].size() < S[y].size()) swap(x, y);

    S[x].insert(S[x].end(),S[y].begin(), S[y].end());//vector
    S[y].clear();
	par[y] = x;
	return true;
}