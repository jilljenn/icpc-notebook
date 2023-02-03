int n, m, source, sink;
vector<tuple<int, int, int, int>> vs[N];
// vs[u].emplace_back(v, arc_id, c, +1);
// vs[v].emplace_back(u, arc_id, 0, -1);
int flow[M];
int visited[N], iter;

bool dfs(int u, int f) {
	if (u == sink)
		return true;
	else if (visited[u] < iter) {
		visited[u] = iter;
		for (auto [v, a, c, k] : vs[u]) if (c - k * flow[a] >= f && dfs(v, f)) {
			flow[a] += k * f;
			return true;
		}
	}
	return false;
}

int maxflow() {
	int f = 0;
	int df = 1 << 20; // >= cmax
	while (df > 0) {
		iter++;
		if (dfs(source, df))
			f += df;
		else
			df /= 2;
	}
	return f;
}
