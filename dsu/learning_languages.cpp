/**
  * http://codeforces.com/contest/277/problem/A
  */

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> l(107, vector<int>());
vector<int> p(107, 0);
vector<int> r(107, 0);
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
	} else if (r[ra] > r[rb]) {
		p[rb] = ra;
	} else {
		p[ra] = rb;
		r[rb]++;
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		cnt += !k;
		for (int j = 0; j < k; j++) {
			int a; scanf("%d", &a);
			l[a].push_back(i);
		}
	}
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < l[i].size(); j++) {
			merge(l[i][0], l[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) ans += (p[i] == i);
	printf("%d\n", ans - (cnt < ans));
}