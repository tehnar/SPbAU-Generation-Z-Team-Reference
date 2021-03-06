struct Edge {
	int a, b, w;
	Edge(int aa, int bb, int ww): a(aa), b(bb), w(ww) {}
};

int d[MAX_N][MAX_N], p[MAX_N][MAX_N];
vector <int> g[MAX_N], resultingCycle;
vector <Edge> edges;

void ford_bellman(int s, int n) {
	forn(i, n + 1)
		forn(j, n + 1)
			d[i][j] = INF;
	d[0][s] = 0;
	forab(i, 1, n + 1) 
		for (auto e : edges) 
			if (d[i - 1][e.a] < INF && d[i][e.b] > d[i - 1][e.a] + e.w) {
				d[i][e.b] = d[i - 1][e.a] + e.w;
				p[i][e.b] = e.a; 
			}
}

LD karp(int n) {
	int s = n++;
	forn(i, n - 1)
		g[s].pb(sz(edges)), edges.pb(Edge(s, i, 0));
	ford_bellman(s, n);
	LD ans = INF;
	int pos = -1, local_pos = -1, dist = -1;
	forn(v, n - 1) 
		if (d[n][v] != INF) {
			LD local_ans = -INF;
			local_pos = -1;
			forn(k, n)
				if (local_ans <= (d[n][v] - d[k][v]) * (LD)(1) / (n - k)) {
					local_ans = (d[n][v] - d[k][v]) * (LD)(1) / (n - k);
					local_pos = k;
				}
			if (ans > local_ans) {
				ans = local_ans;
				dist = local_pos;
				pos = v;
			}
		}
	if (pos == -1)
		return ans;
	for (int iter = n; iter != dist; iter--) {
		resultingCycle.pb(pos);
		pos = p[iter][pos];
	}		
	reverse(all(resultingCycle));
	return ans;
}
