const int N = 1 << 17;
struct {int s; bool lazy; int x;} t[2 * N];

void update(int u, int n) {
	if (t[u].lazy && u < N)
		t[2 * u] = t[2 * u + 1] = {t[u].x * n / 2, true, t[u].x};
	t[u].lazy = false;
}

void setval(int x, int L, int R, int u = 1, int l = 0, int r = N) {
	update(u, r - l);
	if (L <= l && r <= R)
		t[u] = {(r - l) * x, true, x};
	else if (!(r <= L || R <= l)) {
		int m = (l + r) / 2;
		setval(x, L, R, 2 * u, l, m);
		setval(x, L, R, 2 * u + 1, m, r);
		t[u].s = t[2 * u].s + t[2 * u + 1].s;
	}
}

int sum(int L, int R, int u = 1, int l = 0, int r = N) {
	update(u, r - l);
	if (L <= l && r <= R)
		return t[u].s;
	else if (r <= L || R <= l)
		return 0;
	int m = (l + r) / 2;
	return sum(L, R, 2 * u, l, m) + sum(L, R, 2 * u + 1, m, r);
}
