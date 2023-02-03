int par[N]; // init : iota(par, par + n, 0);
int siz[N]; // init : fill(siz, siz + n, 1);

int rep(int u) {
	if (par[u] == u) return u;
	return par[u] = rep(par[u]);
}

bool merge(int u, int v) {
	u = rep(u), v = rep(v);
	if (u == v) return false;
	if (siz[u] < siz[v]) swap(u, v);
	par[v] = u;
	siz[u] += siz[v];
	return true;
}

