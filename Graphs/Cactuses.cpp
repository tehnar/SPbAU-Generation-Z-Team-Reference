namespace Cactus {
	int used[MAX_N], inCycle[MAX_N], dp[MAX_N], inProcess[MAX_N];
	vi g[MAX_N], sons[MAX_N], st, cycle;
	set<pii> forbidden;
	vector<vi> cycles;
	int curCycle = 0;

	void getCycles(int v, int p) {
		used[v] = 1;
		st.pb(v);
		for (int u : g[v])
			if (u != p && used[u] == 1) {
				cycle.clear();
				fornr (i, sz(st)) {
					cycle.pb(st[i]);
					inCycle[st[i]] = curCycle;
					if (st[i] == u)
						break;
				}		
				curCycle++;
				reverse(all(cycle));
				cycles.pb(cycle);
			}
			else if (u != p && !used[u])
				getCycles(u, v);
		st.pop_back();
		used[v] = 2;
	}

	bool isForbidden(int v, int u) {
	 	return forbidden.count(mp(v, u)) || forbidden.count(mp(u, v));
	}

	void dfs(int v, int p);

	void calcTree(int v, int p) {
		used[v] = 1;
		for (int u : g[v])
			if (u != p && !isForbidden(v, u)) {
				dfs(u, v);
				//calc dp
			}
	}

	void calcCycle(int v, int p) {
		int c = inCycle[v];
		for (int u : cycles[c])
			inProcess[u] = 1;
		for (int u : cycles[c])
			for (int w : g[u])
				if (w != p && inCycle[w] != c)
					dfs(w, u), sons[u].pb(w);
		//calc dp on cactus
		for (int u : cycles[c])
			inProcess[u] = 0, used[u] = 1;
	}

	void dfs(int v, int p) {
		if (used[v])
			return;
		if (!inProcess[v] && inCycle[v] != -1) 
			calcCycle(v, p);
		else
			calcTree(v, p);
	}	

	int init(int n) {
		forn (i, n)
			inCycle[i] = -1;
		getCycles(0, -1);
		forn (i, n)
			used[i] = 0;
		dfs(0, -1);
		return dp[0];
	}
}