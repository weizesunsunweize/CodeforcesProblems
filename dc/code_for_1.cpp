/**
  * http://codeforces.com/contest/768/problem/B
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map<ll, ll> m;
ll dc1(ll n) {
	if (m[n]) return m[n];
	m[n] = dc1(n / 2) + 1 + dc1(n / 2);
	return m[n];
}
ll dc2(ll n, ll s, ll e, ll l, ll r) {
	if (e < l || s > r) return 0;
	if (n == 0 || n == 1) return n;
	return dc2(n / 2, s, s + m[n / 2] - 1, l, r) + dc2(n % 2, s + m[n / 2], s + m[n / 2], l, r) + dc2(n / 2, e - m[n / 2] + 1, e, l, r);
}
int main() {
	ll n, l, r;
	cin >> n >> l >> r;
	m[0] = m[1] = 1;
	dc1(n);
	cout << dc2(n, 1, m[n], l, r) << endl;
	return 0;
}