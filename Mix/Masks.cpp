forn(mask, 1 << d) {
	dp[mask][d] = 1;
	fornr(i, d) {
		dp[mask][i] = dp[mask][i + 1];
		if ((1 << i) & mask)
			dp[mask][i] += dp[mask ^ (1 << i)][i + 1];
	}
	cout << mask << " -> " << dp[mask][0] << '\n';
}

int num[64];

for (ULL i = 0; i < 64; ++i) {
	num[(1ull << i) % 67] = i;
}
