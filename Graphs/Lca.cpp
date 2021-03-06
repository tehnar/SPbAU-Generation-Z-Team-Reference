namespace Lca {
	int tin[MAX_N], tout[MAX_N], up[MAX_N][MAX_LOG];
	vi g[MAX_N];
	int curTime = 0;

	void dfs(int v, int p) {			   	
		up[v][0] = p;
		forn (i, MAX_LOG - 1)
			up[v][i + 1] = up[up[v][i]][i];	
	 	tin[v] = curTime++;
		for (int u : g[v])
			if (u != p)
				dfs(u, v); 	
	 	tout[v] = curTime++;
	}

	int isUpper(int v, int u) {
	 	return tin[v] <= tin[u] && tout[v] >= tout[u];
	}

	int lca(int v, int u) {
	 	if (isUpper(u, v))
	 		return u;
	 	fornr (i, MAX_LOG) 
	 		if (!isUpper(up[u][i], v))
	 			u = up[u][i];
	 	return up[u][0];
	}

	void init() {
	 	dfs(0, 0);
	}
}