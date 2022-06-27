void DFS(int u){
	c[u] = 1; d[u] = d[par[u]] + 1;
	int idMx = -1;
	for(int i=0; i < g[u].size(); i++){
		int v = g[u][i];
		if (v==par[u]) continue;
		par[v] = u;
		DFS(v);
		c[u]+= c[v];
		if (idMx==-1 || c[v]>c[g[u][idMx]]){
			idMx = i;
		}
	}
	if (idMx!=-1) swap(g[u][idMx], g[u][0]);
}
 
void HLD(int u, int curHead){
	Head[u] = curHead;
	pos[u] = ++cnt;
	if (g[u][0]==par[u]) return;
	HLD(g[u][0], curHead);
	for(int i=1; i < g[u].size(); i++){
		int v = g[u][i];
		if (v==par[u]) continue;
		HLD(v,v);
	}
}
 
void Update(int id, int l, int r, int pos, int val){
	if (l==r){
		t[id] = val;
		return;
	}
	int mid = (l+r)/2;
	if (pos<=mid) Update(id*2,l,mid,pos,val);
	else Update(id*2+1,mid+1,r,pos,val);
	t[id] = max(t[id*2],t[id*2+1]);
}
 
int ITQuery(int id, int l, int r, int u, int v){
	if (v<l || r<u) return 0;
	if (u<=l && r<=v){
		return t[id];
	}
	int mid = (l+r)/2;
	return max(ITQuery(id*2,l,mid,u,v), ITQuery(id*2+1,mid+1,r,u,v));
}
 
int Query(int u, int v){
	int res = 0;
	while (Head[u]!=Head[v]){
		if (d[Head[u]] > d[Head[v]]) swap(u,v); //v sau hon
		res = max(res, ITQuery(1,1,n,pos[Head[v]], pos[v]));
		v = par[Head[v]];
	}
	if (pos[u] > pos[v]) swap(u, v);
	res = max(res, ITQuery(1,1,n,pos[u],pos[v]));
	return res;
}
