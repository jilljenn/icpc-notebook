int n, m;
int deg[N];
// non orienté : deg[u]++ ; deg[v]++
// orienté : deg[u]-- ; deg[v]++
vector<pair<int, int>> vs[N];
// non orienté : vs[u].push_back(v, e) ; vs[v].push_back(u, e)
// orienté : vs[u].push_back(v, a)
vector<int> path;
bool visited[M];

void dfs(int u) {
	for (auto e : vs[u]) if (!visited[e.second]) {
		visited[e.second] = true;
		dfs(e.first);
		path.push_back(e.second);
	}
}

bool eulercycle(bool oriented) {
	for (int u = 0; u < n; u++) {
		if (oriented && deg[u] != 0) return false;
		else if (!oriented && deg[u] % 2 != 0) return false;
	}
	dfs(0);
	reverse(path.begin(), path.end());
	return true;
}

bool eulerpath(bool oriented) {
	int s = 0;
	for (int u = 0; u < n; u++) {
		if (oriented && deg[u] > deg[s]) s = u;
		else if (!oriented && deg[u] % 2 == 1) s = u;
	}
	dfs(s);
	reverse(path.begin(), path.end());
	return path.size() == 0;
}
