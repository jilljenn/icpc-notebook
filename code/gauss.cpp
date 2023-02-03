const double EPSILON = 1e-6;

bool solvegauss(vector<vector<double>> A, vector<double> b, vector<double> &x) {
	int m = A.size();
	int n = A[0].size();
	for (int p = 0; p < min(n, m); p++) {
		int i = p, k = p;
		for (int i = p; i < m; i++)
			if (abs(A[i][p]) > abs(A[k][p]))
				k = p;
		swap(A[k], A[p]);
		swap(b[k], b[p]);
		if (abs(A[p][p]) > EPSILON) {
			double k = A[p][p];
			for (int j = 0; j < n; j++)
				A[p][j] /= k;
			b[p] /= k;
			for (int i = 0; i < m; i++) if (i != p) {
				double k = A[i][p];
				for (int j = 0; j < n; j++)
					A[i][j] -= k * A[p][j];
				b[i] -= k * b[p];
			}
		}
	}
	x.resize(n);
	for (int p = 0; p < min(n, m); p++) {
		if (A[p][p] > EPSILON) x[p] = b[p];
		else if (abs(b[p]) > EPSILON) return false;
	}
	for (int p = n; p < m; p++) if (abs(b[p]) > EPSILON)
		return false;
	return true;
}
