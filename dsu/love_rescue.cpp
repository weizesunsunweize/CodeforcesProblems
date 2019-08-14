/**
  * http://codeforces.com/contest/939/problem/D
  */

#include<bits/stdc++.h>
using namespace std;
int n, p[130], r[130] = {0}, s[130] = {0};
char s1[100007], s2[100007];
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
	scanf("%d", &n);
	scanf("%s", s1);
	scanf("%s", s2);
	for (int i = 0; i < n; i++) {
		p[s1[i]] = s1[i];
		p[s2[i]] = s2[i];
		s[s1[i]] = 1;
		s[s2[i]] = 1;
	}
	for (int i = 0; i < n; i++)
		merge(s1[i], s2[i]);
	int ans = 0;
	for (int i = 'a'; i <= 'z'; i++)
		if (p[i] == i)
			ans += s[i] - 1;
	printf("%d\n", ans);
	for (int i = 'a'; i <= 'z'; i++)
		if (p[i] && p[i] != i)
			printf("%c %c\n", i, p[i]);
	return 0;
}