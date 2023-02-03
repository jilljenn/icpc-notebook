vector<int> suffixarray(string s) {
	int n = s.size();
	vector<int> suf(n), rank(n, 0);
	iota(suf.begin(), suf.end(), 0);
	for (int i = 0; i < n; i++)
		rank[i] = s[i];
	for (int k = 1; k < n; k *= 2) {
		auto lt = [&] (int i, int j) -> bool {
			int ri = i + k < n? rank[i + k] : 0;
			int rj = j + k < n? rank[j + k] : 0;
			return rank[i] < rank[j] || (rank[i] == rank[j] && ri < rj);
		};
		sort(suf.begin(), suf.end(), lt);
		int r = 0, p = suf[0];
		for (int i : suf) if (lt(p, i)) {
			p = i;
			rank[i] = r++;
		}
	}
	return suf;
}
