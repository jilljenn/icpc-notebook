typedef vector<double> Vec;
typedef vector<Vec> Mat;
enum Status {OPTIMAL, INFEASIBLE, UNBOUNDED};
const double EPSILON = 1e-5;

void pivot(Mat& A, Vec& b, Vec& c, Vec& d, int* N, int* B, int k, int l) {
	int m = b.size();
	int n = c.size();
	swap(B[k], N[l]);
	double a = A[k][l];
	for (int i = 0; i < m; i++) if (i != k) {
		for (int j = 0; j < n; j++) if (j != l)
			A[i][j] -= A[i][l] * A[k][j] / a;
		b[i] -= A[i][l] * b[k] / a;
		A[i][l] /= -a;
	}
	for (int j = 0; j < n; j++) if (j != l) {
		c[j] -= c[l] * A[k][j] / a;
		d[j] -= d[l] * A[k][j] / a;
		A[k][j] /= a;
	}
	A[k][l] = 1 / a;
	b[k] /= a;
	c[l] /= -a;
	d[l] /= -a;
}

Status simplexiters(Mat& A, Vec& b, Vec& c, Vec& d, int* N, int* B, Vec& x, int xfea) {
	int m = b.size();
	int n = c.size();
	while (true) {
		int l = -1;
		for (int j = 0; j < n; j++)
			if (N[j] != xfea && c[j] < -EPSILON && (l == -1 || N[j] < N[l]))
				l = j;
		if (l == -1)
			break;

		double t = 1e9;
		int k = -1;
		for (int i = 0; i < m; i++)
			if (A[i][l] > 0 && b[i] / A[i][l] < t)
				t = b[i] / A[i][l], k = i;
		if (k == -1)
			return UNBOUNDED;
		pivot(A, b, c, d, N, B, k, l);
	}
	x.resize(n + m);
	fill(x.begin(), x.end(), 0);
	for (int i = 0; i < m; i++)
		x[B[i]] = b[i];
	return OPTIMAL;
}

Status simplex(Mat A, Vec b, Vec c, Vec& x) {
	int m = b.size();
	int n = c.size();
	for (int i = 0; i < m; i++)
		A[i].push_back(-1);
	c.push_back(0);
	Vec d(n + 1);
	d[n] = 1;
	int N[n + 1]; iota(N, N + n + 1, 0);
	int B[m]; iota(B, B + m, n + 1);
	int k = 0;
	for (int i = 0; i < m; i++) if (b[i] < b[k])
		k = i;
	if (b[k] < 0) { // feasability
		pivot(A, b, c, d, N, B, k, n);
		assert(simplexiters(A, b, d, c, N, B, x, -1) == OPTIMAL);
		if (x[n] > EPSILON)
			return INFEASIBLE;
		int k = -1;
		for (int i = 0; i < m; i++) if (B[i] == n)
			k = i;
		if (k != -1) {
			int l = 0;
			for (int j = 0; j < n + 1; j++)
				if (abs(A[k][j]) > abs(A[k][l]))
					l = j;
			assert(abs(A[k][l]) > EPSILON);
			pivot(A, b, c, d, N, B, k, l);
		}
	}
	if (simplexiters(A, b, c, d, N, B, x, n) == UNBOUNDED)
		return UNBOUNDED;
	x.resize(n);
	return OPTIMAL;
}
