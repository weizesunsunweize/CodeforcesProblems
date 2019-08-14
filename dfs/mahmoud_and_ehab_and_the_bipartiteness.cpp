/**
  * http://codeforces.com/contest/862/problem/B
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, l = 0, r = 0;
int b[100007] = {1};
vector<int> e[100007];
void dfs(int u, int f) {
	if (b[f] == 1) {
		b[u] = -1;
		r++;
	} else {
		b[u] = 1;
		l++;
	}
	for (int i = 0; i < e[u].size(); i++)
		if (e[u][i] != f)
			dfs(e[u][i], u);
}
int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	printf("%lld\n", l * r - n + 1);
	return 0;
}