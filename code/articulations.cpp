int n, m;
vector<int> vs[N];
int depth[N];
bool articulation[N];

int dfs(int u, int p = -1, int d = 0) {
	if (depth[u] != -1)
		return depth[u];
	int low = depth[u] = d;
	int deg = 0;
	for (int v : vs[u]) if (v != p) {
		deg += depth[v] == -1;
		if (depth[v] != -1) {
			int r = dfs(v, u, d + 1);
			low = min(low, r);
		} else {
			int r = dfs(v, u, d + 1);
			low = min(low, r);
			if (r >= depth[u] && p != -1)
				articulation[u] = true;
		}
	}
	if (p == -1)
		articulation[u] = deg > 1;
	return low;
}
