/**
  * http://codeforces.com/contest/446/problem/A
  */

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, a[100007], l[100007], r[100007], ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		l[i] = cnt;
		cnt = (i == 0 || a[i] > a[i - 1]? cnt + 1: 1);
	}
	cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		r[i] = cnt;
		cnt = (i == n - 1 || a[i] < a[i + 1]? cnt + 1: 1);
	}
	for (int i = 0; i < n; i++) {
		ans = max(ans, 1 + l[i]);
		ans = max(ans, 1 + r[i]);
		if (i > 0 && i < n - 1 && a[i - 1] + 1 < a[i + 1]) ans = max(ans, 1 + l[i] + r[i]);
	}
	cout << ans << endl;
	return 0;
}