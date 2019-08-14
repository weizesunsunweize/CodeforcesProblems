/**
  * http://codeforces.com/contest/676/problem/C
  */

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	int a = 0, b = 0, ans = 0, l = 0;
	for (int i = 0; i < n; i++) {
		s[i] == 'a'? a++: b++;
		while (min(a, b) > k) s[l++] == 'a'? a--: b--;
		ans = max(ans, a + b);
	}
	cout << ans << endl;
	return 0;
}