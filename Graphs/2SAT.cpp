//MAX_N - 2 * vars
vector <int> g[MAX_N], rg[MAX_N], tsort;
vector <bool> values;
int used[MAX_N], comp[MAX_N];

void dfs(int v) {
	used[v] = 1;
	for(int to : g[v])
		if (!used[to])
			dfs(to);
	tsort.pb(v);
}

void rdfs(int v, int num) {
	used[v] = 1;
	comp[v] = num;
	for(int to : rg[v]) 
		if (!used[to])
			rdfs(to, num);
}

void addEdge(int a, int b) {
	g[a ^ 1].pb(b);
	g[b ^ 1].pb(a);
	rg[b].pb(a ^ 1);
	rg[a].pb(b ^ 1);
}
//n - удвоенное
bool sat2(const vector <pii> &v, int n) {
	forn(i, sz(v)) {
		addEdge(v[i].fst, v[i].snd); 
	}
	memset(used, 0, sizeof(used));
	forn(i, n)
		if (!used[i])
			dfs(i);
	memset(used, 0, sizeof(used));
	int num = 0;
	fornr(i, n) {
		int u = tsort[i];
		if (!used[u])
			rdfs(u, num), num++;
	}
	values.resize(n);
	for(int i = 0; i < n; i += 2)
		if (comp[i] == comp[i ^ 1])
			return 0;
		else if (comp[i] > comp[i ^ 1])
			values[i] = 1, values[i ^ 1] = 0;
		else
			values[i] = 0, values[i ^ 1] = 1;
	return 1;
}
