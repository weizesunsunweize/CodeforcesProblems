/**
  * http://codeforces.com/contest/682/problem/C
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, a[100007], s[100007] = {0};
vector<pair<int, ll>> e[100005];
int dfs1(int u, int f) {
	int cnt = 1;
	for (int i = 0; i < e[u].size(); i++)
		if (e[u][i].first != f)
			cnt += dfs1(e[u][i].first, u);
	s[u] = cnt;
	return cnt;
}
int dfs2(int u, int f, ll acc, ll m) {
	if (a[u] < acc - m) return s[u];
	int cnt = 0;
	for (int i = 0; i < e[u].size(); i++)
		if (e[u][i].first != f)
			cnt += dfs2(e[u][i].first, u, acc + e[u][i].second, min(m, acc + e[u][i].second));
	return cnt;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++) {
		int p;
		ll c;
		scanf("%d%lld", &p, &c);
		e[i].push_back(make_pair(p, c));
		e[p].push_back(make_pair(i, c));
	}
	dfs1(1, 0);
	printf("%d\n", dfs2(1, 0, 0, 0));
	return 0;
}