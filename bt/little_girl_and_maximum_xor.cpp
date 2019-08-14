/**
  * http://codeforces.com/contest/276/problem/D
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll a, b;
	cin >> a >> b;
	for (int i = 63; i >= 0; i--)
		if ((a / (1LL << i)) ^ (b / (1LL << i))) {
			cout << (1LL << (i + 1)) - 1 << endl;
			return 0;
		}
	cout << 0 << endl;
	return 0;
}