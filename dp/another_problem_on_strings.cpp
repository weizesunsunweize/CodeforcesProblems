/**
  * http://codeforces.com/contest/165/problem/C
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int k, m[1000007] = {1}, cnt = 0;
string s;
ll ans = 0;
int main() {
	cin >> k >> s;
	for (int i = 0; i < s.size(); i++) {
		cnt += (s[i] == '1'? 1: 0);
		ans += (cnt - k >= 0? m[cnt - k]: 0);
		m[cnt]++;
	}
	cout << ans << endl;
	return 0;
}