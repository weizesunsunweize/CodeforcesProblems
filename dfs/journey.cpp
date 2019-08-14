/**
  * http://codeforces.com/contest/839/problem/C
  */

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> e[100007];
double dfs(int u, int f) {
	double ans = 0;
	int cnt = 0;
	for (int i = 0; i < e[u].size(); i++)
		if (e[u][i] != f) {
			ans += dfs(e[u][i], u);
			cnt++;
		}
	return cnt? 1 + ans / cnt: 0;
	
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	printf("%f\n", dfs(1, 0));
	return 0;
}