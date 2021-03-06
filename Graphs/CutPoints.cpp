struct Edge {
	int to, id;
	Edge(int aa, int bb) : to(aa), id(bb) {}
};

vector<Edge> g[MAX_N]; // (to, id)
vector<int> st; // stack
bool used[MAX_M];
int tin[MAX_N], timer, is_cut[MAX_N], color[MAX_M], compCnt;

int dfs(int v, int parent = -1) {
	tin[v] = ++timer;
	int up = tin[v], x = 0, y = (parent != -1);
	for (Edge p : g[v]){
		int u = p.to, id = p.id;
		if (id != parent) {
			int t, size = sz(st);
			if (!used[id]){
				st.push_back(id);
				used[id] = 1;
			}
			if (!tin[u]) { // not visited yet
				t = dfs(u, id);
				if (t >= tin[v]){
					++x, ++compCnt;
					while(sz(st) != size){
						color[st.back()] = compCnt;
						st.pop_back();
					}
				}
			} else
				t = tin[u];
			up = min(up, t);
		}
	}
	if(x + y >= 2)
		is_cut[v] = 1; // v is cut vertex
	return up;
}
