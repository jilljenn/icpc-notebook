#include <bits/stdc++.h>
using namespace std;

vector<complex<double>> fft(vector<complex<double>> pol, bool inv)
{
	// i = (e << l) + p
	// even(i) = (e << l + 1 | p) & (sz - 1)
	// odd(i) = (e << l + 1 | 1 << l | p) & (sz - 1)
	// odd(i) = e << l + 1 | 1 << l | p
	// w[k] = exp(-/+2iPi*k/sz)
	// val[i] = val[even(i)] + w[e2^l]val[odd(i)]
	int sz = pol.size();
	int logsz = __builtin_ctz(sz);
	vector<complex<double>> w(sz);
	for (int e = 0; e < sz; e++)
	{
		double arg = (inv? -2 : +2) * M_PI * e / sz;
		w[e] = complex<double>(cos(arg), sin(arg));
	}

	for (int l = logsz - 1; l >= 0; l--)
	{
		vector<complex<double>> val(sz);
		for (int i = 0; i < sz; i++)
		{
			int p = i & (1 << l) - 1;
			int e = i - p;
			int even = (e << 1 | p) & (sz - 1);
			int odd = (e << 1 | 1 << l | p) & (sz - 1);
			val[i] = pol[even] + w[e] * pol[odd];
		}
		pol = val;
	}

	if (inv) for (auto &z : pol) z /= sz;
	return pol;
}
