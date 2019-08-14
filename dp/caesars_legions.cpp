/**
  * http://codeforces.com/contest/118/problem/D
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000000
int n1, n2, k1, k2;
ll dpf[107][107][17] = {0}, dph[107][107][17] = {0}, ans = 0;
int main() {
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	dpf[1][0][1] = dph[0][1][1] = 1;
	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			for (int k = 1; k <= k1; k++) {
				dph[i][j + 1][1] += dpf[i][j][k];
				dph[i][j + 1][1] %= mod;
				dpf[i + 1][j][k + 1] += dpf[i][j][k];
				dpf[i + 1][j][k + 1] %= mod;
			}
			for (int k = 1; k <= k2; k++) {
				dpf[i + 1][j][1] += dph[i][j][k];
				dpf[i + 1][j][1] %= mod;
				dph[i][j + 1][k + 1] += dph[i][j][k];
				dph[i][j + 1][k + 1] %= mod;
			}
		}
	}
	for (int i = 1; i <= k1; i++) {
		ans += dpf[n1][n2][i];
		ans %= mod;
	}
	for (int i = 1; i <= k2; i++) {
		ans += dph[n1][n2][i];
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}