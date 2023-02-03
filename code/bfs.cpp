int n;
vector<int> vs[N];

vector<int> bfs(int u0) {
	vector<int> dist(n, n + 1);
	queue<int> q;
	dist[u0] = 0;
	q.push(u0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : vs[u]) if (dist[v] == n + 1) {
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
	return dist;
}
