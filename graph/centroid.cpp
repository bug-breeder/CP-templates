struct CentroidDecomposition{
    set <int> adj[N];
    map <int, int> dis[N];
    int sz[N], pa[N], ans[N];
    void init(int n){
        for (int i = 1; i <= n; i++)
            adj[i].clear(), dis[i].clear(), ans[i] = N;
    }
    void addEgde(int u, int v){
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int dfs(int u, int p){
        sz[u] = 1;
        for (int v : adj[u]){
            if (v == p) continue;
            sz[u] += dfs(v, u);
        }
        return sz[u];
    }
    int centroid(int u, int p, int node){
        for (int v : adj[u]) if (v != p){
            if (sz[v] > node/2)
                return centroid(v, u, node);
        }
        return u;
    }
    void dfs2(int u, int p, int c, int d){ // build distance
        dis[c][u] = d;
        for (int v : adj[u]) if (v != p){
            dfs2(v, u, c, d + 1);
        }
    }
    void build_tree(int u, int p){
        int numnode = dfs(u, p);
        int cen = centroid(u, p, numnode);
        if (p == -1) p = cen;
        pa[cen] = p;
        dfs2(cen, p, cen, 0);
        vector <int> tmp(adj[cen].begin(), adj[cen].end());
        for (int v : tmp){
            adj[cen].erase(v);
            adj[v].erase(cen);
            build_tree(v, cen);
        }
    }
    void update(int u){
        int v = u;
        while (v != 0){
            ans[v] = min(ans[v], dis[v][u]);
            v = pa[v];
        }
    }
    int query(int u){
        int v = u, mi =N;
        while (v != 0){
            mi = min(mi, ans[v] + dis[v][u]);
            v = pa[v];
        }
        return mi;
    }
 
}