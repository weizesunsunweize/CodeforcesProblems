/**
  * http://codeforces.com/contest/505/problem/B
  */
  
#include<bits/stdc++.h>
using namespace std;
int n, m, r[107][107] = {0}, p[107][107] = {0};
int find(int u, int c) {
	int temp = u;
	while (p[temp][c] != temp) temp = p[temp][c];
	p[u][c] = temp;
	return temp;
}
void merge(int u, int v, int c) {
	int ra = find(u, c), rb = find(v, c);
	if (ra == rb) return;
	if (r[ra][c] < r[rb][c]) {
		p[ra][c] = rb;
	} else if (r[ra][c] > r[rb][c]) {
		p[rb][c] = ra;
	} else {
		p[ra][c] = rb;
		r[rb][c]++;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) p[i][j] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		merge(a, b, c);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int u, v, ans = 0;
		scanf("%d%d", &u, &v);
		for (int i = 1; i <= m; i++) ans += (find(u, i) == find(v, i));
		printf("%d\n", ans);
	}
	return 0;
}