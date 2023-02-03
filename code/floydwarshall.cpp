void floydwarshall(vector<vector<int>>& d) {
	// d[u][v] = c(u, v) si (u, v) arc et +oo sinon
	int n = d.size();
	for (int w = 0; w < n; w++)
		for (int u = 0; u < n; u++)
			for (int v = 0; v < n; v++)
				d[u][v] = min(d[u][v], d[u][w] + d[w][v]);
}
