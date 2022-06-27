void DFS(int u){
	Low[u] = Num[u] = ++cnt;
	st.push(u);
	for(int v: g[u]){
		if (Id[v]) continue;
		if (Num[v]) Low[u] = min(Low[u], Num[v]);
		else{
			DFS(v);
			Low[u] = min(Low[u], Low[v]);
		}
	}
	if (Low[u] == Num[u]){
		int v=0; nComp++;
		do{
			v = st.top(); st.pop();
			Id[v] = nComp;
		} while (v!=u);
	}
}
 