void mergesort(int* a, int l, int r) {
	if (r - l > 1) {
		int m = (l + r) / 2;
		mergesort(a, l, m);
		mergesort(a, m, r);
		int p[m - l]; copy(a + l, a + m, p);
		int q[r - m]; copy(a + m, a + r, q);
		for (int i = l, j = 0, k = 0; i < r; i++) {
			if (j == m - l) a[i] = q[k++];
			else if (k == r - m) a[i] = p[j++];
			else if (p[j] <= q[k]) a[i] = p[j++];
			else a[i] = q[k++]; // + (m - l - j) inversions
		}
	}
}
