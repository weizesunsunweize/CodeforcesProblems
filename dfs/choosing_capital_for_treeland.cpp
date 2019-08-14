/**
  * http://codeforces.com/contest/219/problem/D
  */

#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<pair<int, int>>> e(200007, vector<pair<int, int>>());
vector<int> ans(200007, 0);
void dfs1(int u, int p) {
	for (int i = 0; i < e[u].size(); i++) {
		if (e[u][i].first == p) continue;
		dfs1(e[u][i].first, u);
		ans[u] += ans[e[u][i].first] + e[u][i].second;
	}
}
void dfs2(int u, int p) {
	if (p) {
		for (int i = 0; i < e[u].size(); i++) {
			if (e[u][i].first == p) {
				ans[u] = ans[p] + (e[u][i].second? 1: -1);
				break;
			}
		}
	}
	for (int i = 0; i < e[u].size(); i++) {
		if (e[u][i].first == p) continue;
		dfs2(e[u][i].first, u);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int s, t;
		scanf("%d%d", &s, &t);
		e[s].push_back(make_pair(t, 0));
		e[t].push_back(make_pair(s, 1));
	}
	dfs1(1, 0);
	dfs2(1, 0);
	int mini = 0x7FFFFFFF;
	for (int i = 1; i <= n; i++) mini = min(mini, ans[i]);
	printf("%d\n", mini);
	for (int i = 1; i <= n; i++)
		if (ans[i] == mini)
			printf("%d ", i);
	printf("\n");
	return 0;
}