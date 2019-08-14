/**
  * http://codeforces.com/contest/339/problem/C
  */

#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int m;
	cin >> s >> m;
	int dp[1007][21][10] = {0};
	for (int i = 0; i < 10; i++) 
		if (s[i] == '1')
			dp[0][i + 11][i] = -1;
		
	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j < 21; j++)
			for (int k = 0; k < 10; k++)
				for (int l = 0; l < 10; l++)
					if (s[l] == '1' && dp[i][j][k] && k != l)
						if (j < 10 && j + l + 1 > 10) dp[i + 1][j + l + 1][l] = k + 1;
						else if (j > 10 && j - l - 1 < 10) dp[i + 1][j - l - 1][l] = k + 1;
						
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 10; j++)
			if (dp[m - 1][i][j]) {
				printf("YES\n");
				int y = i, z = j;
				stack<int> s;
				for (int x = m - 1; x >= 0; x--) {
					s.push(z);
					int temp1 = (y > 10? y - z - 1: y + z + 1), temp2 = dp[x][y][z] - 1;
					y = temp1;
					z = temp2;
				}
				while (!s.empty()) {
					printf("%d ", s.top() + 1);
					s.pop();
				}
				printf("\n");
				return 0;
			}
	printf("NO\n");
	return 0;
}