/**
  * http://codeforces.com/contest/932/problem/B
  */

#include<bits/stdc++.h>
using namespace std;
vector<int> e[1000007];
int dp[10][1000007] = {0};
void dfs1(int u, int f) {
	if (u % 10) f *= u % 10;
	e[f].push_back(u);
	if (u >= 100000) return;
	for (int i = 0; i <= 9; i++) dfs1(u * 10 + i, f);
}
void dfs2(int u, int r) {
	dp[r][u] = 1;
	for (int i = 0; i < e[u].size(); i++)
		if (e[u][i] != u)
			dfs2(e[u][i], r);
}
int main() {
	for (int i = 1; i <= 9; i++) dfs1(i, 1);
	e[1].push_back(1000000);
	for (int i = 1; i <= 9; i++) {
		dfs2(i, i);
		for (int j = 1; j <= 1000000; j++) dp[i][j] += dp[i][j - 1];
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", dp[k][r] - dp[k][l - 1]);
	}
	return 0;
}