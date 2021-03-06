const int ALPHA = 26;
const int MAX_N = 1e5;

struct Node {
	int next[ALPHA], term; //Бор
	int go[ALPHA], suf, p, pch; //Автомат
	Node() {
		memset(next, -1, sizeof(next));
		term = 0;
		memset(go, -1, sizeof(go));
		suf = p = -1;
	}
};

Node g[MAX_N];
int last;

void add(const string &s) {
	int now = 0;
	for(char x : s) { // x -= 'a'
		if (g[now].next[x] == -1) {
			g[now].next[x] = ++last;
			g[last].p = now;
			g[last].pch = x;
		} 
		now = g[now].next[x];
	}
	g[now].term = 1;
}

int go(int v, int c);

int get_link(int v) {
	if (g[v].suf == -1) { 
		if (!v || !g[v].p)
			g[v].suf = 0;
		else
			g[v].suf = go(get_link(g[v].p), g[v].pch);
	}
	return g[v].suf;
}

int go(int v, int c) {
	if (g[v].go[c] == -1) {
		if (g[v].next[c] != -1)
			g[v].go[c] = g[v].next[c];
		else
			g[v].go[c] = !v ? 0 : go(get_link(v), c);
	}
	return g[v].go[c];
}
