void BFS(int u){
	queue<int> q;
	q.push(u);
	while (!q.empty()){
		int u = q.front(); q.pop();
		if (u==n/*dest*/) return;
		FOR(v, 1, n){
			if (!tr[v] && f[u][v] < c[u][v]){
				tr[v] = u;
				q.push(v);
			}
		}
	}
}
 
bool findPath(){
	fill(tr+1, tr+n+1, 0);
	tr[1] = -1;
	BFS(1/*src*/);
	return tr[n];
}
 
void pushFlow(){
	int v = n;
	while (v!=1){
		int u = tr[v];
		f[u][v]++;
		f[v][u]--;
		v = u;
	}
	maxFlow++;
}
 
