namespace Math {
	vi eratosthenes(int n) {
		vi minDiv(n + 1, 0);
		minDiv[1] = 1;
		for (int i = 2; i <= n; i++)
			if (minDiv[i] == 0) 
				for (int j = i; j <= n; j += i)
					if (minDiv[j] == 0)
						minDiv[j] = i; 
		return minDiv;
	}

	vi eratosthenesFast(int n) {
		vi minDiv(n + 1, 0);
		vi primes;
		minDiv[1] = 1;
		for (int i = 2; i <= n; i++) {
			if (minDiv[i] == 0) {
				minDiv[i] = i;
				primes.pb(i);
			}
			for (int j = 0; j < sz(primes) && primes[j] <= minDiv[i] && i * primes[j] <= n; j++)
				minDiv[i * primes[j]] = primes[j];
		}	
		return minDiv;
	}
}