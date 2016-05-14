struct Line {
	int k, b;
	Line() {}
	Line(int kk, int bb): k(kk), b(bb) {}
	LL get(int x) {
		return b + k * 1ll * x;
	}
	bool operator <(const Line &l) const {
		return k < l.k; //знак на > если в другую сторону
	}
};
//проверяет, что пересечение (a,b) левее (a,c)
inline bool check(Line a, Line b, Line c) { 
	return (a.b - b.b) * 1ll * (c.k - a.k) < (a.b - c.b) * 1ll * (b.k - a.k);
}

vector <Line> st;

inline void add(Line l) {
	while(sz(st) >= 2 && !check(st[sz(st) - 2], st[sz(st) - 1], l))
		st.pop_back();
	st.pb(l);
}

int get(int x) {
	int l = 0, r = sz(st);
	while (r - l > 1) {
		int m = (l + r) / 2; //знак на > если в другую сторону
		if ((st[m - 1].b - st[m].b) < x * 1ll * (st[m].k - st[m - 1].k))
			l = m;
		else
			r = m;
	}
	return l;
}

void buildConvexHull(vector <Line> lines) {
	sort(all(lines));
	for(Line l : lines)
		add(l);
}