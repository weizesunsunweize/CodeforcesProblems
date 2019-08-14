/**
  * http://codeforces.com/contest/534/problem/B
  */

#include<bits/stdc++.h>
using namespace std;
int main() {
	int v1, v2, t, d, ans = 0;;
	cin >> v1 >> v2 >> t >> d;
	for (int i = 0; i < t; i++)
		ans += min(v1 + i * d, v2 + (t - i - 1) * d);
	cout << ans << endl;
}