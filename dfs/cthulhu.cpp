/**
  * http://codeforces.com/contest/103/problem/B
  */

#include<bits/stdc++.h>
using namespace std;
int n, m;
bool vis[107] = {false};
vector<int> e[107];
void dfs(int u) {
	if (vis[u]) return;
	vis[u] = true;
	for (int i = 0; i < e[u].size(); i++) dfs(e[u][i]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1);
	int flag = true;
	for (int i = 1; i <= n; i++) flag &= vis[i];
	flag && n == m? printf("FHTAGN!\n"): printf("NO\n");
	return 0;
}