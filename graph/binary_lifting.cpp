void DFS(int u, int par, int du /* length of the path from par to v */){
    In[u]= ++cnt;
    up[u][0] = par;
    Max[u][0] = du;
    depth[u] = depth[par] + 1;
 
    for(int i=1; i<M; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
        Max[u][i] = max(Max[u][i-1], Max[up[u][i-1]][i-1]);
    }
    for(auto tmp: g[u]){
	int v = tmp.first, uv = tmp.second;
        if (v==par) continue;
        DFS(v,u, uv);
    }
    Out[u] = ++cnt;
}
 
int Upper(int u, int v){
    return (In[u] <= In[v] && Out[u] >= Out[v]);
}
 
int LCA(int u, int v){
    if (Upper(u,v)) return u;
    if (Upper(v,u)) return v;
    for(int i=M-1; i>=0; i--){
        if (up[u][i] > 0 && !Upper(up[u][i],v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}
 
int getMax(int u, int p){
    //p must be an ancestor of u
    //query(u, v) => query(u, lca(u,v)) & query(v, lca(u, v))
    if (u==p) return 0;
    int ret = Max[u][0];
    for(int i=M-1; i >=0 ;i--){
        if (up[u][i] > 0 && !Upper(up[u][i], p)) {
            ret = max(ret, Max[u][i]);
            u = up[u][i];
        }
    }
    return max(ret, Max[u][0]);
}
