int n, m;
vector<pair<int, int>> vs[N];
int depth[N];
bool bridge[M];

int dfs(int u, int p = -1, int d = 0) {
	if (depth[u] != -1)
		return depth[u];
	depth[u] = d;
	for (auto [v, e] : vs[u]) if (v != p) {
		int r = dfs(v, u, d + 1);
		if (r <= d)
			bridge[e] = false;
		depth[u] = min(depth[u], r);
	}
	return depth[u];
}
