/**
  * http://codeforces.com/contest/598/problem/D
  */

#include<bits/stdc++.h>
using namespace std;
int n, m, k, vis[1007][1007] = {0}, c[1007][1007] = {0}, r = 0;
vector<int> ans(1, 0);
char g[1007][1007];
int dfs(int x, int y) {
	if (g[x][y] == '*') return 1;
	if (c[x][y]) return 0;
	c[x][y] = r;
	int cnt = 0;
	if (x > 0) cnt += dfs(x - 1, y);
	if (x < n - 1) cnt += dfs(x + 1, y);
	if (y > 0) cnt += dfs(x, y - 1);
	if (y < m - 1) cnt += dfs(x, y + 1);
	vis[x][y] = cnt;
	ans[r] = max(ans[r], vis[x][y]);
	return vis[x][y];
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) scanf("%s", g[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] == '.' && !vis[i][j]) {
				r++;
				ans.push_back(0);
				dfs(i, j);
			}
	while (k--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", ans[c[x - 1][y - 1]]);
	}
	return 0;
}