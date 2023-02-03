int n, m;
vector<tuple<int, int, int>> vs[N];
bool visited[N];
vector<int> mst;

void prim() {
	priority_queue<tuple<int, int, int>> q;
	q.emplace(-0, 0, -1);
	while (!q.empty()) {
		auto [c, u, e] = q.top();
		q.pop();
		if (!visited[u]) {
			visited[u] = true;
			if (e != -1)
				mst.push_back(e);
			for (auto [v, d, f] : vs[u])
				q.emplace(-d, v, f);
		}
	}
}
