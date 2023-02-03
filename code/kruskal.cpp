int n;
int par[N];

int rep(int u) {
	return par[u] = par[u] == u? u : rep(par[u]);
}

vector<int> kruskal(vector<tuple<int, int, int, int>> edge) {
	sort(edge.begin(), edge.end());
	iota(par, par + n, 0);
	vector<int> mst;
	for (auto [c, u, v, e] : edge) if (rep(u) != rep(v)) {
		par[rep(u)] = rep(v);
		mst.emplace_back(e);
	}
	return mst;
}
