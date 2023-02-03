tuple<vector<map<char, int>>, vector<int>, vector<bool>> automaton(string s) {
	int n = s.size();
	vector<int> len(2 * n);
	vector<map<char, int>> next(2 * n);
	vector<int> link(2 * n);
	int sz = 1, last = 0;
	link[0] = -1;
	for (char c : s) {
		int cur = sz++;
		len[cur] = len[last] + 1;
		int u = last;
		while (u != -1 && next[u].count(c) == 0) {
			next[u][c] = cur;
			u = link[u];
		}
		if (u == -1)
			link[cur] = 0;
		else if (int v = next[u][c]; len[v] == len[u] + 1)
			link[cur] = v;
		else {
			int w = sz++;
			len[w] = len[u] + 1;
			next[w] = next[v];
			link[w] = link[v];
			link[v] = link[cur] = w;
			while (u != -1 && next[u][c] == v)
			{
				next[u][c] = w;
				u = link[u];
			}
		}
		last = cur;
	}
	next.resize(sz);
	len.resize(sz);
	vector<bool> suf(sz);
	while (last != -1) suf[last] = true, last = link[last];
	return {next, len, suf};
}
