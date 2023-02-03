typedef complex<double> Z;
double det(Z u, Z v) {return imag(conj(u) * v);}
double dot(Z u, Z v) {return real(conj(u) * v);}
const Z I(0, 1);

const double EPSILON = 1e-6;
bool fzero(double x) {return abs(x) < EPSILON;}
bool feq(double x, double y) {return abs(x - y) < EPSILON;}
bool flt(double x, double y) {return x < y - EPSILON;}
bool fleq(double x, double y) {return x <= y + EPSILON;}
bool fgt(double x, double y) {return x > y + EPSILON;}
bool fgeq(double x, double y) {return x >= y - EPSILON;}
// norm(u); |u|^2
// abs(u); |u|^2

bool ltarg(Z u, Z v) {
	if (!(abs(u) > 0))
		return abs(v) > 0;
	bool pu = imag(u) > 0 || !(imag(u) < 0) && real(u) > 0;
	bool pv = imag(v) > 0 || !(imag(v) < 0) && real(v) > 0;
	if (pu != pv)
		return pu < pv;
	return det(u, v) > 0;
}
