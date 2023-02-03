const int N = 1 << 17; // power of 2

struct Node {int s; Node *v, *w;};

Node* setval(Node *u, int i, int x, int l = 0, int r = N) {
	if (!u) u = new Node {0, nullptr, nullptr};
	else u = new Node {0, u->v, u->w};
	if (r - l == 1)
		u->s = x;
	else {
		int m = (l + r) / 2;
		if (i < m) u->v = setval(u->v, i, x, l, m);
		else u->w = setval(u->w, i, x, m, r);
		u->s = (u->v? u->v->s : 0) + (u->w? u->w->s : 0);
	}
	return u;
}

int sum(Node *u, int L, int R, int l = 0, int r = N) {
	if (!u || r <= L || l >= R) return 0;
	else if (L <= l && r <= R) return u->s;
	int m = (l + r) / 2;
	return sum(u->v, L, R, l, m) + sum(u->w, L, R, m, r);
}
