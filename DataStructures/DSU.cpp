namespace DSU {
	int pr[MAX_N], rank[MAX_N]; 	

 	int get(int v) {
 		return v == pr[v] ? v : pr[v] = get(pr[v]);
 	}

 	void unite(int v, int u) {
 	 	v = get(v), u = get(u);
 	 	if (v == u)
 	 		return;
 	 	if (rank[v] < rank[u])
 	 		swap(v, u);
 	 	pr[u] = v;
 	 	if (rank[v] == rank[u])
 	 		++rank[v];
 	}

 	void init(int n) {
		forn (i, n)
			rank[i] = 0, pr[i] = i;
 	}
}