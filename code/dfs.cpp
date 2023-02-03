vector<int> vs[N];
int visited[N];

void dfs(int u) {
	if (visited[u] == 1)
		/*...*/;
	else if (visited[u] == 2)
		/*...*/;
	else {
		visited[u] = 1;
		for (int v : vs[u])
			dfs(v);
		visited[u] = 2;
	}
}
