/**
  * http://codeforces.com/contest/763/problem/A
  */
  
#include<bits/stdc++.h>
using namespace std;
int n, c[100007];
vector<int> e[100007];
bool dfs(int u, int f) {
	bool ans = true;
	for (int i = 0; i < e[u].size(); i++) {
		if (e[u][i] == f) continue;
		ans &= (c[u] == c[e[u][i]] && dfs(e[u][i], u));
		if (!ans) break;
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 0; i < n; i++) scanf("%d", &c[i + 1]);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < e[i].size(); j++) {
			int u = i, v = e[i][j];
			if (c[u] != c[v]) {
				bool ans;
				ans = true;
				for (int k = 0; k < e[u].size(); k++) {
					ans = ans && dfs(e[u][k], u);
					if (!ans) break;
				}
				if (ans) {
					printf("YES\n%d\n", u);
					return 0;
				}
				ans = true;
				for (int k = 0; k < e[v].size(); k++) {
					ans = ans && dfs(e[v][k], v);
					if (!ans) break;
				}
				if (ans) {
					printf("YES\n%d\n", v);
					return 0;
				}
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n%d\n", 1);
	return 0;
}