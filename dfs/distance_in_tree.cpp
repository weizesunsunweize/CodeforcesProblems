/**
  * http://codeforces.com/contest/161/problem/D
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
ll dp[50007][507] = {0};
vector<int> e[50007];
int dfs(int u, int f) {
	ll cnt = 0, temp = 0;
	dp[u][0] = 1;
	for (int i = 0; i < e[u].size(); i++)
		if (e[u][i] != f) {
			cnt += dfs(e[u][i], u);
			for (int j = 1; j <= k; j++)
				dp[u][j] += dp[e[u][i]][j - 1];
		}
	for (int i = 0; i < e[u].size(); i++)
		if (e[u][i] != f)
			for (int j = 0; j <= k - 2; j++)
				temp += dp[e[u][i]][j] * (dp[u][k - 1 - j] - dp[e[u][i]][k - 2 - j]);
	cnt += temp / 2 + dp[u][k];
	return cnt;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cout << dfs(1, 0) << endl;
	return 0;
}