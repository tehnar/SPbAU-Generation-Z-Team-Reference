//z[i] - с позиции i сколько матчится
int l = -1, r = -1;
z[0] = 0;
for (int i = 1; i < n; i++) {
	int k = 0;
	if (r >= i)
		k = min(z[i - l], r - i);
	while (i + k < n && s[i + k] == s[k])
		k++;
	z[i] = k;
	if (i + z[i] > r)
		l = i, r = i + z[i];
}
