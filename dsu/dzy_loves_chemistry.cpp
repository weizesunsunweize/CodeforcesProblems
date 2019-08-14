/**
  * http://codeforces.com/contest/445/problem/B
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, p[57], r[57], s[57], ans = 0;
int find(int a) {
	int temp = a;
	while (temp != p[temp]) temp = p[temp];
	p[a] = temp;
	return temp;
}
void merge(int a, int b) {
	int ra = find(a), rb = find(b);
	if (ra == rb) return;
	if (r[ra] < r[rb]) {
		p[ra] = rb;
		s[rb] += s[ra];
	} else if (r[ra] > r[rb]) {
		p[rb] = ra;
		s[ra] += s[rb];
	} else {
		p[rb] = ra;
		r[ra]++;
		s[ra] += s[rb];
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		s[i] = 1;
	}
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		merge(x, y);
	}
	for (int i = 1; i <= n; i++)
		if (p[i] == i)
			ans += s[i] - 1;
	printf("%lld\n", 1LL << ans);
	return 0;
}