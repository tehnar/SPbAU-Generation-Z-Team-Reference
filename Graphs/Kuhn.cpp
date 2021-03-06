//первая доля - n вершин вторая доля - m вершин
//нумерация сквозная
const int MAX_N = 1e5 + 100;

int n, m, paired[2 * MAX_N], used[2 * MAX_N];
vector <int> g[MAX_N];

bool dfs(int v) {
	if (used[v])
		return false;
	used[v] = 1;
	for(int to : g[v]) 
		if (paired[to] == -1 || dfs(paired[to])) {
			paired[to] = v;
			paired[v] = to;
			return true;
		}
	return false;
}

int kuhn() {
	int ans = 0;
	forn(i, n + m)
		paired[i] = -1;
	for (int run = 1; run;) { 
		run = 0;
		memset(used, 0, sizeof(used));
		forn(i, n) 
			if (!used[i] && paired[i] == -1 && dfs(i)) {
				ans++;
				run = 1;
			}
	}
	return ans;
}
//Стартуем из вершин без пары из первой доли, ходим из первой доли, из второй - только по парсочу.
//Max независимое - A+, B-
//Min покрытие    - A-, B+ 

vector <int> minCover, maxIndependent;

void dfsCoverIndependent(int v) {
	if (used[v])
		return;
	used[v] = 1;
	for(int to : g[v]) 
		if (!used[to])
			used[to] = 1, dfsCoverIndependent(paired[to]);
}

//Сперва Куна
void findCoverIndependent() {
	memset(used, 0, sizeof(used));
	forn(i, n)
		if (paired[i] == -1)
			dfsCoverIndependent(i);
	forn(i, n)
		if(used[i])
			maxIndependent.pb(i);
		else
			minCover.pb(i);
	forab(i, n, n + m)
		if (used[i])
			minCover.pb(i);
		else 
			maxIndependent.pb(i);
}
