int dfs(int v) {
	forn(i, n + 1)
		dp[v][i] = -INF;
	dp[v][1] = num[v];
	int mxsz = 1;
	for (int to : g[v]) {
		int size = dfs(to);
		forba(i, 1, mxsz + 1)
			fornr(j, size + 1)
				dp[v][i + j] = max(dp[v][i + j], dp[v][i] + dp[to][j]);
		mxsz += size;
	}
	return mxsz;
}
