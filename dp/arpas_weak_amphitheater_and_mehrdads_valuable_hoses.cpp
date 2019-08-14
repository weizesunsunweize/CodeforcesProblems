/**
  * http://codeforces.com/contest/741/problem/B
  */

#include<bits/stdc++.h>
using namespace std;
int n, m, t, w[1007], b[1007], p[1007], r[1007] = {0}, dp[1007][1007] = {0};
vector<int> g[1007];
map<int, vector<int>> mp;
int find(int u) {
	int temp = u;
	while (temp != p[temp]) temp = p[temp];
	p[u] = temp;
	return temp;
}
void merge(int u, int v) {
	int ru = find(u), rv = find(v);
	if (ru == rv) return;
	if (r[ru] > r[rv]) {
		p[rv] = ru;
	} else if (r[ru] < r[rv]) {
		p[ru] = rv;
	} else {
		p[ru] = rv;
		r[rv]++;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) p[i] = i;
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		merge(x, y);
	}
	for (int i = 1; i <= n; i++)
		g[find(i)].push_back(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++)
			dp[i][j] = dp[i - 1][j];
		for (int j = 0; j < g[i].size(); j++)
			for (int k = 0; k <= t; k++)
				if (w[g[i][j]] <= k)
					dp[i][k] = max(dp[i - 1][k - w[g[i][j]]] + b[g[i][j]], dp[i][k]);
		if (g[i].size() > 1) {
			int sumw = 0, sumb = 0;
			for (int j = 0; j < g[i].size(); j++) {
				sumw += w[g[i][j]];
				sumb += b[g[i][j]];
			}
			for (int j = 0; j <= t; j++)
				if (sumw <= j)
					dp[i][j] = max(dp[i - 1][j - sumw] + sumb, dp[i][j]);
		}
	}
	printf("%d\n", dp[n][t]);
	return 0;
}