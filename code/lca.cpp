const int LOG_N = 17;
const int N = 1 << LOG_N;

int n;
vector<int> childs[N];
int depth[N];
int par[LOG_N + 1][N];

void dfs(int u) {
	for (int v : childs[u]) {
		par[0][v] = u;
		depth[v] = depth[u] + 1;
		dfs(v);
	}
}

void build(int root) {
	fill_n((int*)par, (LOG_N + 1) * N, root);
	par[0][root] = root;
	depth[root] = 0;
	dfs(root);
	for (int k = 0; k < LOG_N; k++)
		for (int u = 0; u < n; u++)
			par[k + 1][u] = par[k][par[k][u]];
}

int lca(int u, int v) {
	if (depth[u] > depth[v])
		swap(u, v);
	for (int k = LOG_N; k >= 0; k--)
		if ((depth[v] - depth[u]) & (1 << k))
			v = par[k][v];
	if (u == v)
		return u;
	for (int k = LOG_N; k >= 0; k--)
		if (par[k][u] != par[k][v])
			u = par[k][u], v = par[k][v];
	return par[0][u];
}
