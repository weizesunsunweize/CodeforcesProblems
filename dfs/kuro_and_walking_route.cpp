/**
  * http://codeforces.com/contest/979/problem/C
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int x, y;
vector<int> e[300007];
int dfs(int u, int f) {
	int ans = 1;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (v == f) continue;
		int temp = dfs(v, u);
		if (temp < 0) return temp;
		else ans += temp;
	}
	return (u == y? -ans: ans);
}
int main() {
	scanf("%lld%d%d", &n, &x, &y);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	ll temp1 = 1, temp2;
	for (int i = 0; i < e[x].size(); i++) {
		int v = e[x][i];
		int temp = dfs(v, x);
		if (temp > 0) temp1 += temp;
		else temp2 = -temp;
	}
	printf("%lld\n", n * (n - 1) - temp1 * temp2);
	return 0;
}