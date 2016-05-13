// pr[len] - для префикса длины len
int k = 0;
pr[0] = pr[1] = 0;
for (int i = 2; i <= n; i++) {
	k = pr[i - 1];
	while (k && s[k] != s[i - 1])
		k = pr[k];
	if (s[k] == s[i - 1])
		k++;
	pr[i] = k;
}
