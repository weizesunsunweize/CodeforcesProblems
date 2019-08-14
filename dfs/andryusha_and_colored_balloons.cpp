/**
  * http://codeforces.com/contest/780/problem/C
  */

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> e[200007], c(200007, 0);
void dfs(int u, int f) {
	int j = 1;
	for (int i = 0; i < e[u].size(); i++) {
		if (e[u][i] == f) continue;
		while (j == c[u] || j == c[f]) j++;
		c[e[u][i]] = j++;
		dfs(e[u][i], u);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	c[1] = 1;
	dfs(1, 0);
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, c[i]);
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) printf("%d ", c[i]);
	printf("\n");
	return 0;
}