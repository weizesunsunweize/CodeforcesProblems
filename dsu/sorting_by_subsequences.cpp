/**
  * http://codeforces.com/contest/843/problem/A
  */

#include<bits/stdc++.h>
using namespace std;
int n, ans = 0, p[100007], r[100007];
pair<int, int> a[100007];
unordered_map<int, vector<int>> m;
int find(int u) {
	int temp = u;
	while (temp != p[temp]) temp = p[temp];
	p[u] = temp;
	return temp;
}
void merge(int u, int v) {
	int ru = find(u), rv = find(v);
	if (ru == rv) return;
	if (r[ru] < r[rv]) {
		p[ru] = rv;
	} else if (r[ru] > r[rv]) {
		p[rv] = ru;
	} else {
		p[rv] = ru;
		r[ru]++;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		a[i] = make_pair(temp, i);
		p[i] = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) merge(i, a[i].second);
	for (int i = 0; i < n; i++)
		m[find(i)].push_back(i + 1);
	printf("%d\n", (int)m.size());
	for (auto it = m.begin(); it != m.end(); it++) {
		printf("%d ", (int)(it->second).size());
		for (int i = 0; i < (it->second).size(); i++)
			printf("%d ", (it->second)[i]);
		printf("\n");
	}
	return 0;
}