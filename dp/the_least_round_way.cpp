/**
  * http://codeforces.com/contest/2/problem/B
  */
  
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> prev2(n, vector<int>(n, 0));
	vector<vector<int>> prev5(n, vector<int>(n, 0));
	vector<int> dp2(n, 0);
	vector<int> dp5(n, 0);
	int zero = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			scanf("%d", &num);
			int t = 0, f = 0;
			if (num) {
				while (num && num % 2 == 0) {
					t++;
					num /= 2;
				}
				while (num && num % 5 == 0) {
					f++;
					num /= 5;
				}
			} else {
				zero = i;
				f++;
				t++;
			}
			if (i && j) {
				if (dp2[j] < dp2[j - 1]) {
					prev2[i][j] = 1;
					dp2[j] = dp2[j] + t;
				} else {
					prev2[i][j] = 0;
					dp2[j] = dp2[j - 1] + t;
				}
				if (dp5[j] < dp5[j - 1]) {
					prev5[i][j] = 1;
					dp5[j] = dp5[j] + f;
				} else {
					prev5[i][j] = 0;
					dp5[j] = dp5[j - 1] + f;
				}
			} else if (!i && j) {
				prev2[i][j] = 0;
				dp2[j] = dp2[j - 1] + t;
				prev5[i][j] = 0;
				dp5[j] = dp5[j - 1] + f;
			} else if (i && !j) {
				prev2[i][j] = 1;
				dp2[j] = dp2[j] + t;
				prev5[i][j] = 1;
				dp5[j] = dp5[j] + f;
			} else {
				dp2[0] = t;
				prev2[0][0] = -1;
				dp5[0] = f;
				prev5[0][0] = -1;
			}
		}
	}
	if (zero >= 0 && min(dp2.back(), dp5.back()) > 1) {
		printf("1\n");
		for (int i = 0; i < zero; i++) printf("%c", 'D');
		for (int i = 0; i < n - 1; i++) printf("%c", 'R');
		for (int i = 0; i < n - 1 - zero; i++) printf("%c", 'D');
		printf("\n");
	} else {
		stack<char> s;
		int i = n - 1, j = n - 1;
		if (dp2.back() < dp5.back()) {
			printf("%d\n", dp2.back());
			while (i || j) {
				if (prev2[i][j]) {
					s.push('D');
					i--;
				} else {
					s.push('R');
					j--;
				}
			}
		} else {
			printf("%d\n", dp5.back());
			while (i || j) {
				if (prev5[i][j]) {
					s.push('D');
					i--;
				} else {
					s.push('R');
					j--;
				}
			}
		}
		while (!s.empty()) {
			printf("%c", s.top());
			s.pop();
		}
		printf("\n");
	}
}