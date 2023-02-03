const int LOG_N = 17;
const int N = 1 << LOG_N;
const int oo = INT_MAX;

int range[LOG_N + 1][N];

void build(vector<int>& a) {
	int n = a.size();
	fill_n((int*)range, (LOG_N + 1) * N, +oo);
	for (int i = 0; i < n; i++)
		range[0][i] = a[i];
	for (int k = 0; k < LOG_N; k++) {
		for (int i = 0; i < n; i++) {
			int j = i + (1 << k);
			range[k + 1][i] = min(
					range[k][i],
					j < n? range[k][j] : +oo
				);
		}
	}
}

int rmq(int l, int r) {
	int k = 0;
	int n = r - l;
	while (n > 1)
		k++, n /= 2;
	return min(range[k][l], range[k][r - (1 << k)]);
}
