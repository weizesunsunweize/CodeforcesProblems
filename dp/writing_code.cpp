/**
  * http://codeforces.com/contest/543/problem/A
  */

#include<bits/stdc++.h>
using namespace std;
int n, m, b, mod, a, dp[507][507] = {1};
int main() {
	scanf("%d%d%d%d", &n, &m, &b, &mod);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		for (int j = 1; j <= m; j++)
			for (int k = a; k <= b; k++)
				dp[j][k] = (dp[j - 1][k - a] + dp[j][k]) % mod;
	}
	int ans = 0;
	for (int i = 0; i <= b; i++)
		ans = (ans + dp[m][i]) % mod;
	printf("%d\n", ans);
	return 0;
}