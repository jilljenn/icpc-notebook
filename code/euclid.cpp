// g++ function __gcd(a, b)
// gcd(a0, a1) = a0 u0 + a1 v0
int euclid(int a0, int a1, int& u0, int& v0) {
	u0 = 1, v0 = 0;
	int u1 = 0, v1 = 1;
	while (a1 != 0)
	{
		int q = a0 / a1;
		a0 -= q * a1; swap(a0, a1);
		u0 -= q * u1; swap(u0, u1);
		v0 -= q * v1; swap(v0, v1);
	}
	return a0;
}
