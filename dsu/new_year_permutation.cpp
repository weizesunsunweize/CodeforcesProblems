/**
  * http://codeforces.com/contest/500/problem/B
  */

#include<bits/stdc++.h>
using namespace std;
int n, m[307], p[307], r[307];
vector<int> v[307];
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
		p[rb] = ra;
		r[ra]++;
	}
}
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m[i]);
		p[i] = i;
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				merge(i, j);
	}
	for (int i = 0; i < n; i++)
		v[find(i)].push_back(m[i]);
	for (int i = 0; i < n; i++)
		sort(v[i].begin(), v[i].end(), cmp);
	for (int i = 0; i < n; i++) {
		m[i] = v[find(i)].back();
		v[find(i)].pop_back();
	}
	for (int i = 0; i < n; i++)
		printf("%d ", m[i]);
	printf("\n");
	return 0;
}