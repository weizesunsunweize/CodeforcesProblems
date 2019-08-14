/**
  * http://codeforces.com/contest/902/problem/B
  */
 
#include<bits/stdc++.h>
using namespace std;
int n, c[10007], ans = 0;
vector<int> e[10007];
void dfs(int u, int f) {
	ans += (c[u] != c[f]);
	for (int i = 0; i < e[u].size(); i++) {
		if (e[u][i] == f) continue;
		dfs(e[u][i], u);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p;
		scanf("%d", &p);
		e[p].push_back(i);
	}
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}