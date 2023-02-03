const int N = 1 << 17;
int t[2 * N];

void build() {
	for (int u = N - 1; u >= 1; u--)
		t[u] = t[2 * u] + t[2 * u + 1];
}

void setval(int u, int x)
{
	u += N;
	t[u] = x;
	while (u > 1)
	{
		u /= 2;
		t[u] = t[2 * u] + t[2 * u + 1];
	}
}

int sum(int u, int v) { // sum on [u:v[
	int s = 0;
	u += N, v += N;
	while (u < v) {
		if (u & 1) s += t[u++];
		if (v & 1) s += t[--v];
		u /= 2, v /= 2;
	}
	return s;
}
