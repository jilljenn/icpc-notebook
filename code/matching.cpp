int nl, nr;
vector<int> vs[NL]; // vs[ul].push_back(vr);
int lmatch[NL];
int rmatch[NR];
int visited[NR], iter;

bool dfs(int u) {
	if (visited[u] < iter) {
		visited[u] = iter;
		for (int v : vs[u]) {
			if (rmatch[v] == -1 || dfs(rmatch[v])) {
				lmatch[u] = v;
				rmatch[v] = u;
				return true;
			}
		}
	}
	return false;
}

int maxmatching() {
	fill(lmatch, lmatch + nl, -1);
	fill(rmatch, rmatch + nr, -1);
	int m = 0, dm = 1;
	while (dm > 0) {
		dm = 0;
		iter++;
		for (int u = 0; u < nl; u++) if (lmatch[u] == -1)
			dm += dfs(u);
		m += dm;
	}
	return m;
}
