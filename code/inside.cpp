bool inside(vector<Z> &a, Z z) {
	int n = a.size();
	for (int i = 0; i < n; i++) {
		Z p = a[i], q = a[(i + 1) % a.size()];
		double t = dot(q - p, z - p);
		double s = norm(q - p);
		if (fzero(det(q - p, z - p)) && fgeq(t, 0) && fleq(t, s))
			return true; // sur un cote
	}
	Z u; // tirer une demi droite qui ne coupe pas un sommets de a
	bool dir = true;
	while (dir) {
		double theta = 2 * acos(-1) * (double)rand() / RAND_MAX;
		u = Z(cos(theta), sin(theta));
		dir = false;
		for (Z p : a) if (fzero(det(p - z, u)))
			dir = true;
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		Z p = a[i], q = a[(i + 1) % n];
		if (!fzero(det(p - q, u))) {
			double t = det(p - z, u) / det(p - q, u);
			double s = det(p - q, p - z) / det(p - q, u);
			k += fgeq(t, 0) && fleq(t, 1) && fgeq(s, 0);
		}
	}
	return k % 2;
}
