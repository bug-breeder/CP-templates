struct dsu
{
	vector<int> par;

	dsu(int n)
	{
		par.resize(n + 1);
		for (int i = 0; i <= n; i++)
			par[i] = i;
	}

	int find(int x)
	{
		if (x == par[x])
			return x;
		return par[x] = find(par[x]);
	}

	bool merge(int a, int b)
	{
		int x = find(a), y = find(b);
		if (x == y)
			return false;
		if (x > y)
			swap(x, y);
		par[y] = x;
		return true;
	}
};
