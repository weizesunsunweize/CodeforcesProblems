/**
  * http://codeforces.com/contest/722/problem/C
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, d[100007], p[100007], r[100007], f[100007] = {0};
ll a[100007], s[100007], ans = 0;
stack<ll> st;
int find(int b) {
	int temp = b;
	while (temp != p[temp]) temp = p[temp];
	p[b] = temp;
	return temp;
}
void merge(int b, int c) {
	int rb = find(b), rc = find(c);
	if (rb == rc) return;
	if (r[rb] < r[rc]) {
		p[rb] = rc;
		s[rc] += s[rb];
	} else if (r[rb] > r[rc]) {
		p[rc] = rb;
		s[rb] += s[rc];
	} else {
		p[rc] = rb;
		s[rb] += s[rc];
		r[rb]++;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		s[i] = a[i];
		p[i] = i;
	}
	st.push(0);
	for (int i = 0; i < n; i++) scanf("%d", &d[i]);
	for (int i = n - 1; i > 0; i--) {
		int b = d[i];
		f[b] = 1;
		if (b > 1 && f[b - 1]) merge(b, b - 1);
		if (b < n && f[b + 1]) merge(b, b + 1);
		ans = max(ans, s[find(b)]);
		st.push(ans);
	}
	while (!st.empty()) {
		printf("%lld\n", st.top());
		st.pop();
	}
	return 0;
}