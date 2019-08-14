/**
  * http://codeforces.com/contest/25/problem/D
  */
  
#include<bits/stdc++.h>
using namespace std;
vector<int> p(1007, 0);
vector<int> r(1007, 0);
vector<pair<int, int>> d;
int find(int a) {
	int temp = a;
	while (p[temp] != temp) temp = p[temp];
	p[a] = temp;
	return temp;
}
void merge(int a, int b) {
	int ra = find(a), rb = find(b);
	if (ra == rb) {
		d.push_back(make_pair(a, b));
		return;
	}
	if (r[ra] < r[rb]) {
		p[ra] = rb;
	} else if (r[ra] > r[rb]) {
		p[rb] = ra;
	} else {
		p[rb] = ra;
		r[ra]++;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	vector<int> roots;
	for (int i = 1; i <= n; i++)
		if (p[i] == i)
			roots.push_back(i);
	printf("%d\n", (int)roots.size() - 1);
	while (d.size()) {
		printf("%d %d %d %d\n", d.back().first, d.back().second, roots.back(), roots[roots.size() - 2]);
		roots.pop_back();
		d.pop_back();
	}
	return 0;
}