void Dijkstra(){
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0,1));
	fill(d+2, d+n+1, 1e14);
 
	while (!pq.empty()){
		int u = pq.top().se;
		ll du = pq.top().fi;
		pq.pop();
		if (du > d[u]) continue;
 
		for(ii t: g[u]){
			int v = t.se;
			ll uv = t.fi;
			if (du + uv < d[v]){
				d[v] = du + uv;
				pq.push(ii(d[v],v));
			}
		}
	}
}
