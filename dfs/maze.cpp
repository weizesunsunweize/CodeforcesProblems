/**
  * http://codeforces.com/contest/377/problem/A
  */

#include<bits/stdc++.h>
using namespace std;
int n, m, k;
string g[507];
set<pair<int, int>> vis;
bool dfs(int i, int j) {
	if (vis.find(make_pair(i, j)) != vis.end()) return true;
	vis.insert(make_pair(i, j));
	bool flag = true;
	if (i > 0 && g[i - 1][j] == '.') flag &= dfs(i - 1, j);
	if (i < n - 1 && g[i + 1][j] == '.') flag &= dfs(i + 1, j);
	if (j > 0 && g[i][j - 1] == '.') flag &= dfs(i, j - 1);
	if (j < m - 1 && g[i][j + 1] == '.') flag &= dfs(i, j + 1);
	if (k && flag) {
		k--;
		g[i][j] = 'X';
	}
	return flag;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) cin >> g[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] == '.') {
				dfs(i, j);
				for (int i = 0; i < n; i++)
					cout << g[i] << endl;
				return 0;
			}
	for (int i = 0; i < n; i++)
		cout << g[i] << endl;
	return 0;
}