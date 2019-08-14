/**
  * http://codeforces.com/contest/371/problem/D
  */

#include<bits/stdc++.h>
using namespace std;
int n, a[200007], m, p[200007], r[200007] = {0}, b[200007], w[200007] = {0};
int find(int u) {
	int temp = u;
	while (temp != p[temp]) temp = p[temp];
	p[u] = temp;
	return temp;
}
void merge(int u, int v) {
	int ru = find(u), rv = find(v);
	int temp = max(b[find(ru)], b[find(rv)]);
	if (ru == rv) return;
	if (r[ru] < r[rv]) {
		p[ru] = rv;
	} else if (r[ru] > r[rv]) {
		p[rv] = ru;
	} else {
		p[rv] = ru;
		r[ru]++;
	}
	b[find(ru)] = temp;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		p[i] = i;
		b[i] = i;
	}
	p[n + 1] = n + 1;
	b[n + 1] = n + 1;
	scanf("%d", &m);
	while (m--) {
		int ins;
		scanf("%d", &ins);
		if (ins == 1) {
			int q, x;
			scanf("%d%d", &q, &x);
			while (x + w[b[find(q)]] > a[b[find(q)]]) {
				if (b[find(q)] > n) {
					x = 0;
					break;
				}
				x -= a[b[find(q)]] - w[b[find(q)]];
				w[b[find(q)]] = a[b[find(q)]];
				merge(b[find(q)], b[find(q)] + 1);
			}
			w[b[find(q)]] += x;
		} else {
			int k;
			scanf("%d", &k);
			printf("%d\n", w[k]);
		}
	}
	return 0;
}