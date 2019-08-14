/**
  * http://codeforces.com/contest/893/problem/C
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, p[100007], r[100007];
ll c[100007], ans = 0;
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
		c[rb] = min(c[ra], c[rb]);
	} else if (r[ra] > r[rb]) {
		p[rb] = ra;
		c[ra] = min(c[ra], c[rb]);
	} else {
		p[rb] = ra;
		r[ra]++;
		c[ra] = min(c[ra], c[rb]);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);
		p[i] = i;
	}
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		merge(x, y);
	}
	for (int i = 1; i <= n; i++)
		if (p[i] == i)
			ans += c[i];
	printf("%lld\n", ans);
	return 0;
}