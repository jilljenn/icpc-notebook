vector<int> childs[N];
int depth[N], pos[N];
vector<pair<int, int>> euler;

void dfs(int u) {
	pos[u] = euler.size();
	euler.emplace_back(depth[u], u);
	for (int v : childs[u]) {
		depth[v] = depth[u] + 1;
		dfs(v);
		euler.emplace_back(depth[u], u);
	}
}

// dfs(root);
// [d, lca] = rmq(min(pos[u], pos[v]), max(pos[u], pos[v]) + 1);
