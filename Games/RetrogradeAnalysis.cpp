namespace Games {
	vi g[MAX_N]; //reversed edges
	int win[MAX_N], lose[MAX_N], used[MAX_N], deg[MAX_N];

	void dfs(int v) {
		used[v] = 1;
		for (int u : g[v])
			if (!used[u]) {
			 	if (lose[v])
			 		win[u] = 1;
			 	else if (--deg[u] == 0)
			 		lose[u] = 1;
			 	else
			 		continue;
			 	dfs(u);	
			}
	}

	void retrogradeAnalysis(int n, vi initLose, vi initWin) {
		for (int v : initLose)
			lose[v] = 1;
		for (int v : initWin)
			win[v] = 1;
		forn (i, n)
			if (!used[i] && (win[i] || lose[i]))
				dfs(i);
	}
}
	