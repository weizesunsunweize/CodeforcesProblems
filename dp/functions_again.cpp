/**
  * http://codeforces.com/contest/788/problem/A
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll a, preva, ans, o = 0, e = 0;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a);
		if (i == 1) {
			o = abs(a - preva);
			preva = a;
		} else if (i == 2) {
			ll temp = abs(a - preva);
			e = temp;
			o -= temp;
			preva = a;
		} else if (i > 2) {
			ll temp = abs(a - preva);
			if (i % 2) {
				o = (o > 0? o + temp: temp);
				e -= temp;
			} else {
				o -= temp;
				e = (e > 0? e + temp: temp);
			}
		}
		ans = max(ans, max(o, e));
		preva = a;
	}
	printf("%lld\n", ans);
	return 0;
}