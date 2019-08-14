/**
  * http://codeforces.com/contest/727/problem/A
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b;
deque<ll> dfs(ll u) {
	if (u == b) {
		return deque<ll>(1, u);
	}
	if (u * 2 <= b) {
		deque<ll> v = dfs(u * 2);
		if (v.size()) {
			v.push_front(u);
			return v;
		}
	}
	if (u * 10 + 1 <= b) {
		deque<ll> v = dfs(u * 10 + 1);
		if (v.size()) {
			v.push_front(u);
			return v;
		}
	}
	return deque<ll>();
}
int main() {
	scanf("%lld%lld", &a, &b);
	deque<ll> v = dfs(a);
	if (v.size()) {
		cout << "YES" << endl << v.size() << endl;
		for (int i = 0; i < v.size(); i++)
			printf("%lld ", v[i]);
		printf("\n");
	} else {
		printf("NO\n");
	}
	return 0;
}