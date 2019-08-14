/**
  * http://codeforces.com/contest/771/problem/A
  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, p[150007], r[150007] = {0}, s[150007], c[150007];
int find(int a) {
	int temp = a;
	while (p[temp] != temp) temp = p[temp];
	p[a] = temp;
	return temp;
}
void merge(int a, int b) {
	int ra = find(a), rb = find(b);
	if (ra == rb) {
		c[ra]++;
		return;
	}
	if (r[ra] < r[rb]) {
		p[ra] = rb;
		s[rb] += s[ra];
		c[rb] += c[ra] + 1;
	} else if (r[ra] > r[rb]) {
		p[rb] = ra;
		s[ra] += s[rb];
		c[ra] += c[rb] + 1;
	} else {
		p[rb] = ra;
		s[ra] += s[rb];
		c[ra] += c[rb] + 1;
		r[ra]++;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		s[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		merge(a, b);
	}
	for (int i = 1; i <= n; i++)
		if (p[i] == i && c[i] != (ll)s[i] * (ll)(s[i] - 1) / 2) {
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}