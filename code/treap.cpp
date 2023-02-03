struct Treap {
	Treap *l, *r;
	int x;
	int y;
};

Treap* merge(Treap *u, Treap *v) {
	if (!u) return v;
	else if (!v) return u;
	else if (u->y > v->y) {
		u->r = merge(u->r, v);
		return u;
	}
	else {
		v->l = merge(u, v->l);
		return v;
	}
}

pair<Treap*, Treap*> split(Treap *u, int x) {
	if (!u)
		return {nullptr, nullptr};
	else if (u->x <= x) {
		auto [v, w] = split(u->r, x);
		u->r = v;
		return {u, w};
	}
	else {
		auto [v, w] = split(u->l, x);
		u->l = w;
		return {v, u};
	}
}

Treap* insert(Treap *u, int x) {
	int y = rand();
	auto [v, w] = split(u, x);
	Treap *t = new Treap {nullptr, nullptr, x, y};
	return merge(v, merge(t, w));
}

Treap* erase(Treap *u, int x) {
	if (u->x == x)
		return merge(u->l, u->r);
	else if (x < u->x)
		return erase(u->l, x);
	else
		return erase(u->r, x);
}
