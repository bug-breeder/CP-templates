void DFS(int u, int par){
	In[u] = ++cnt;
	p[u][0] = par;
	FOR(i,1,M) p[u][i] = p[p[u][i-1]][i-1];
	for(int v: g[u]){
		if (v==par) continue;
		DFS(v, u);
	}
	Out[u] = ++cnt;
}
 
bool Ancestor(int u, int v){
	return In[u]<=In[v] && Out[u]>=Out[v];
}
 
int LCA(int u, int v){
	if (Ancestor(u,v)) return u;
	if (Ancestor(v,u)) return v;
	FORD(i,M,0){
		if (!Ancestor(p[u][i],v) && p[u][i]>0) u = p[u][i];
	}
	return p[u][0];
}