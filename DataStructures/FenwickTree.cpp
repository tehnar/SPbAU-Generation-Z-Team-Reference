namespace FenwickTree {
	int t[MAX_N];
	int n;

	int get(int ind) {
	 	int res = 0;
	 	for (; ind >= 0; ind &= (ind + 1), ind--)
	 		res += t[ind];
	 	return res;
	}

	void add(int ind, int x) {
	 	for (; ind < n; ind |= (ind + 1))	
	 		t[ind] += x;
	}

	int sum(int l, int r) { //[l, r)
		return get(r - 1) - get(l - 1);
	}
}
