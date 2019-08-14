/**
  * http://codeforces.com/contest/653/problem/B
  */

#include<bits/stdc++.h>
using namespace std;
int n, q;
unordered_map<int, int> e[130];
int dfs(int u, int l) {
	if (l == 1) return 1;
	int ans = 0;
	for (auto it = e[u].begin(); it != e[u].end(); it++)
		ans += it->second * dfs(it->first, l - 1);
	return ans;
}
int main() {
	cin >> n >> q;
	while (q--) {
		string a, b;
		cin >> a >> b;
		e[b[0]][a[0]]++;
	}
	cout << dfs('a', n) << endl;
	return 0;
}