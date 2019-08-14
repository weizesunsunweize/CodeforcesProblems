/**
  * http://codeforces.com/contest/659/problem/E
  */

#include<bits/stdc++.h>
using namespace std;
int n, m, p[100007], r[100007], e[100007], s[100007];
int find(int a) {
	int temp = a;
	while (temp != p[temp]) temp = p[temp];
	p[a] = temp;
	return temp;
}
void merge(int a, int b) {
	int ra = find(a), rb = find(b);
	if (ra == rb) {
		e[ra]++;
		return;
	}
	if (r[ra] < r[rb]) {
		p[ra] = rb;
		e[rb] += e[ra] + 1;
		s[rb] += s[ra];
	} else if (r[ra] > r[rb]) {
		p[rb] = ra;
		e[ra] += e[rb] + 1;
		s[ra] += s[rb];
	} else {
		p[rb] = ra;
		e[ra] += e[rb] + 1;
		s[ra] += s[rb];
		r[ra]++;
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
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += (p[i] == i && s[i] > e[i]);
	printf("%d\n", ans);
	return 0;
}