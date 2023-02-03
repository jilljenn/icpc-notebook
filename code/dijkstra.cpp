const int oo = 1e9;
int n, m;
vector<pair<int, int>> vs[N];
int dist[N];

void dijkstra(int u0) {
	priority_queue<pair<int, int>> q;
	q.emplace(-0, u0);
	while (!q.empty()) {
		auto [d, u] = q.top();
		q.pop();
		if (dist[u] == +oo) {
			dist[u] = -d;
			for (auto [v, c] : vs[u])
				q.emplace(d - c, v);
		}
	}
}
