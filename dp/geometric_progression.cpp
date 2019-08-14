/**
  * http://codeforces.com/contest/567/problem/C
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, k, a;
ll ans = 0;
unordered_map<int, ll> m[3];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a % k == 0) {
			m[2][a] += m[1][a / k];
			m[1][a] += m[0][a / k];
		}
		m[0][a]++;
	}
	for (auto it = m[2].begin(); it != m[2].end(); it++)
		ans += it->second;
	printf("%lld\n", ans);
	return 0;
}