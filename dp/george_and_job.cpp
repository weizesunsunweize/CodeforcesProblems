/**
  * http://codeforces.com/contest/467/problem/C
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, k;
ll p[5007], sum = 0, ans = 0, dp[5007][5007];
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) scanf("%lld", &p[i]);
	for (int i = 0; i < n; i++) {
		sum += p[i];
		if (i < m - 1) {
			continue;
		} else if (i == m - 1) {
			for (int j = 1; j <= k; j++) dp[i][j] = sum;
		} else {
			sum -= p[i - m];
			for (int j = 1; j <= k; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + sum);
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k; j++)
			ans = max(ans, dp[i][j]);
	printf("%lld\n", ans);
	return 0;
}