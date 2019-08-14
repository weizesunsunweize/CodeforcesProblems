/**
  * http://codeforces.com/contest/731/problem/C
  */

#include<bits/stdc++.h>
using namespace std;
int n, m, k, c[200007], p[200007], r[200007], s[200007];
unordered_map<int, int> mp[200007];
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
		s[ra] += s[rb];
		r[ra]++;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		p[i] = i;
		s[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		merge(l, r);
	}
	for (int i = 1; i <= n; i++) 
		mp[find(i)][c[i]]++;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i] != i) continue;
		int temp = 0;
		for (auto it = mp[i].begin(); it != mp[i].end(); it++) temp = max(temp, it->second);
		ans += s[i] - temp;
	}
	printf("%d\n", ans);
	return 0;
}