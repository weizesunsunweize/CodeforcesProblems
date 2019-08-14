/**
  * http://codeforces.com/contest/602/problem/B
  */

#include<bits/stdc++.h>
using namespace std;
int n, pre, a, j = 0, t = 0, ans = 1;
int main() {
	scanf("%d%d", &n, &pre);
	for (int i = 1; i < n; i++) {
		scanf("%d", &a);
		if (a > pre) {
			if (t > 0) j = t;
			t = i;
		}
		else if (a < pre) {
			if (t < 0) j = -t;
			t = -i;
		}
		ans = max(ans, i - j + 1);
		pre = a;
	}
	printf("%d\n", ans);
	return 0;
}