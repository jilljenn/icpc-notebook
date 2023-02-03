int n, m;
vector<int> vs[N];
vector<int> rvs[N];
vector<int> topo;
int scc[N];

void toposort(int u) {
	if (!scc[u]) {
		scc[u] = true;
		for (int v : vs[u])
			toposort(v);
		topo.push_back(u);
	}
}

void markscc(int u, int c) {
	if (scc[u] == -1) {
		scc[u] = c;
		for (int v : rvs[u])
			markscc(v, c);
	}
}

void computescc() {
	fill_n(scc, n, false);
	for (int u = 0; u < n; u++)
		toposort(u);
	reverse(topo.begin(), topo.end());
	fill_n(scc, n, -1);
	int c = 0;
	for (int u : topo) if (scc[u] == -1)
		markscc(u, c++);
}
