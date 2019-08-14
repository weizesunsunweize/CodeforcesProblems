/**
  * http://codeforces.com/contest/607/problem/A
  */

#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> dp;
vector<pair<int, int>> ab;
int main() {
	int n, ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		ab.push_back(make_pair(a, b));
	}
	sort(ab.begin(), ab.end());
	ans = n - 1;
	v.push_back(ab[0].first);
	dp.push_back(0);
	for (int i = 1; i < n; i++) {
		int pos = (int)(lower_bound(v.begin(), v.end(), ab[i].first - ab[i].second) - v.begin());
		dp.push_back((pos == 0? 0: dp[pos - 1]) + v.size() - pos);
		v.push_back(ab[i].first);
		ans = min(dp.back() + n - i - 1, ans);
	}
	printf("%d\n", ans);
	return 0;
}