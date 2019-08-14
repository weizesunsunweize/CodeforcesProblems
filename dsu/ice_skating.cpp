/**
  * http://codeforces.com/problemset/problem/217/A
  */
  
#include<bits/stdc++.h>
using namespace std;
int n, p[107], r[107];
vector<int> xs[1007], ys[1007];
int find(int a) {
	int temp = a;
	while (p[temp] != temp) temp = p[temp];
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
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		xs[x].push_back(i);
		ys[y].push_back(i);
	}
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 1; i <= 1000; i++) {
		if (xs[i].size() > 1) {
			for (int j = 1; j < xs[i].size(); j++)
				merge(xs[i][0], xs[i][j]);
		}
	}
	for (int i = 1; i <= 1000; i++) {
		if (ys[i].size() > 1) {
			for (int j = 1; j < ys[i].size(); j++)
				merge(ys[i][0], ys[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) ans += (p[i] == i);
	printf("%d\n", ans - 1);
	return 0;
}