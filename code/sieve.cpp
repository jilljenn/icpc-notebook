// find prime numbers in O(n log log n)
vector<bool> sieve(int n) {
	vector<bool> prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= n; i++) if (prime[i])
		for (int j = i * i; j <= n; j += i)
			prime[j] = false;
	return prime;
}

// find lowest prime factor and prime numbers in O(n)
vector<int> lpfactor(int n) {
	vector<int> lp(n + 1, 0), prime;
	for (int i = 2; i <= n; i++) if (lp[i] == 0) {
		lp[i] = i;
		pr.push_back(i);
	}
	for (int p : prime) if(p <= lp[i] && i * p <= n)
		lp[i * p] = p;
	return lp;
}
