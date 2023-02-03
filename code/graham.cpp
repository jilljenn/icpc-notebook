vector<Z> grahamscan(vector<Z> p) {
	Z o(1e18, 1e18);
	for (auto& z : p)
		if (real(z) < real(o) || !(real(z) > real(o)) && imag(z) < imag(o))
			o = z;
	sort(p.begin(), p.end(), [&] (Z u, Z v) -> bool {return ltarg(u - o, v - o);});
	vector<Z> c;
	for (auto& z : p) {
		while (c.size() > 2 && det(c[c.size() - 2] - c.back(), z - c.back()) >= 0)
			c.pop_back();
		c.push_back(z);
	}
	return c;
}
