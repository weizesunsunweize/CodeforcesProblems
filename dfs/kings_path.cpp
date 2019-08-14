/**
  * http://codeforces.com/contest/242/problem/C
  */

#include<bits/stdc++.h>
using namespace std;
int main() {
	unordered_map<int, unordered_map<int, bool>> allow;
	int x0, y0, x1, y1, n;
	int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int r, a, b;
		scanf("%d %d %d", &r, &a, &b);
		for (int j = a; j <= b; j++) allow[r][j] = true;
	}
	map<pair<int, int>, int> checked;
	queue<pair<int, int>> q;
	checked[make_pair(x0, y0)] = 0;
	q.push(make_pair(x0, y0));
	while (!q.empty()) {
		pair<int, int> pivot = q.front();
		int x = pivot.first, y = pivot.second;
		q.pop();
		if (x == x1 && y == y1) {
			printf("%d\n", checked[pivot]);
			return 0;
		}
		for (int i = 0; i < 8; i++) {
			if (allow[x + dx[i]][y + dy[i]] && checked.find(make_pair(x + dx[i], y + dy[i])) == checked.end()) {
				checked[make_pair(x + dx[i], y + dy[i])] = checked[pivot] + 1;
				q.push(make_pair(x + dx[i], y + dy[i]));
			}
		}
	}
	printf("-1\n");
	return 0;
}