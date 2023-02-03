vector<int> vs[N];
int par[N];
int heavy[N];
int head[N];
int pos[N];
int curpos;

int dfs(int u, int p = -1) {
	par[u] = p;
	heavy[u] = -1;
	int k = 1, mk = 0;
	for (int v : vs[u]) if (v != p) {
		int vk = dfs(v, u);
		k += vk;
		if (vk > mk)
			mk = vk, heavy[u] = v;
	}
	return k;
}

void heavylight(int u) {
	pos[u] = curpos++;
	if (heavy[u] != -1) {
		head[heavy[u]] = head[u];
		heavylight(heavy[u]);
	}
	for (int v : vs[u]) if (v != par[u] && v != heavy[u]) {
		head[v] = v;
		heavylight(v);
	}
}

void query(int u, int v) {
	while (head[u] != head[v]) {
		if (pos[u] > pos[v])
			swap(u, v);
		/* query on [ pos[head[v]] ... pos[v] + 1 [ */
		v = par[head[v]];
	}
	if (pos[u] > pos[v])
		swap(u, v);
	/* query on [ pos[u] + 1 ... pos[v] + 1 [ */
}

// curpos = 0;
// dfs(root);
// head[root] = root;
// heavylight(root);
