struct Edge {
	int to, id;
	Edge(int aa, int bb) : to(aa), id(bb) {}
};

int up[MAX_N], tin[MAX_N], timer;
vector <Edge> g[MAX_N];
vector <vector <int>> comp;
vector <int> st;

void newComp(int size = 0) {
	comp.emplace_back(); // новая пустая
	while (sz(st) > size) {
		comp.back().pb(st.back());
		st.pop_back();
	}
}

void find_bridges(int v, int parentEdge = -1) {
	if (up[v]) // уже были
		return;
	up[v] = tin[v] = ++timer;
	st.pb(v); // st - stack
	for (Edge e : g[v]) {
		if (e.id == parentEdge)
			continue;
		int u = e.to;
		if (!tin[u]) {
			int size = sz(st);
			find_bridges(u, e.id) ;
			if (up[u] > tin[v])
				newComp(size);
		}
		up[v] = min(up[v], up[u]);
	}
}
//после вызова find_bridges newComp() для корня
void run(int n) {
	forn(i, n) {
		if (!up[i]) {
			find_bridges(i);
			newComp();
		}
	}
}
