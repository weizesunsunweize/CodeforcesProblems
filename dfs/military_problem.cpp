/**
  * http://codeforces.com/contest/1006/problem/E
  */

#include<bits/stdc++.h>
using namespace std;
int n, q, pos[200007], s[200007] = {0};
vector<int> e[200007], ans;
int dfs(int u) {
	int cnt = 1;
	pos[u] = ans.size();
	ans.push_back(u);
	for (int i = 0; i < e[u].size(); i++)
		cnt += dfs(e[u][i]);
	s[u] = cnt;
	return cnt;
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++) {
		int p;
		scanf("%d", &p);
		e[p].push_back(i);
	}
	dfs(1);
	while (q--) {
		int u, k;
		scanf("%d%d", &u, &k);
		if (k > s[u]) printf("-1\n");
		else printf("%d\n", ans[pos[u] + k - 1]);
	}
	return 0;
}