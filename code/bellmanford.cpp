const int oo = 1e9;
int n, m;
int dist[N];
vector<tuple<int, int, int>> edge;

bool bellmanford (int u0) {
	fill_n (dist, n, +oo);
	dist[u0] = 0;
	bool stable = false;
	for (int t = 0; t < n && !stable; t++) {
		stable = true;
		for (auto[u, v, c] : edge) if (dist[u] < +oo && dist[u] + c < dist[v]) {
			dist[v] = dist[u] + c;
			stable = false;
		}
	}
	return stable;
}
