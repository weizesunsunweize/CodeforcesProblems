/**
  * http://codeforces.com/contest/919/problem/D
  */

#include<bits/stdc++.h>
using namespace std;
int n, m, in[300007], vis[300007] = {0}, dp[300007][30] = {0}, ans = 0;
char s[300007];
vector<int> e[300007];
void dfs(int u) {
	if (vis[u] > 0) {
		printf("-1\n");
		exit(0);
	}
	if (vis[u] < 0) return;
	vis[u] = 1;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		dfs(v);
		for (int j = 'a'; j <= 'z'; j++)
			dp[u][j - 'a'] = max(dp[v][j - 'a'] + (j == s[u]? 1: 0), dp[u][j - 'a']);
	}
	if (!e[u].size())
		dp[u][s[u] - 'a'] = 1;
	vis[u] = -1;
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		in[y]++;
	}
	for (int i = 1; i <= n; i++)
		if (!in[i]) {
			dfs(i);
			for (int j = 'a'; j <= 'z'; j++)
				ans = max(ans, dp[i][j - 'a']);
		}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			printf("-1\n");
			return 0;
		}
	printf("%d\n", ans);
	return 0;
}