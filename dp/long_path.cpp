/**
  * http://codeforces.com/contest/407/problem/B
  */

#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main() {
	int n, p[1007], dp[1007] = {0};
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 2; i <= n + 1; i++) {
		dp[i] = (2 * dp[i - 1] - dp[p[i - 1]] + 2) % M;
		dp[i] = (dp[i] < 0? dp[i] + M: dp[i]);
	}
	printf("%d\n", dp[n + 1]);
	return 0;
}