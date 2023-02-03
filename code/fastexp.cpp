int fastexp(int x, int n) {
	if (n == 0)
		return 1;
	int y = fastexp(x, n / 2);
	return (n & 1? x : 1) * y * y;
}
