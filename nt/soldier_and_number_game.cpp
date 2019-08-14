/**
  * http://codeforces.com/contest/546/problem/D
  */

#include<bits/stdc++.h>
using namespace std;
int t, soe[5000007] = {1};
int main() {
	scanf("%d", &t);
	for (int i = 2; i <= 5000000; i++)
		for (int j = 1; i * j <= 5000000; j++)
			if (!soe[i * j])
				soe[i * j] = i;
	for (int i = 2; i <= 5000000; i++)
		soe[i] = (soe[i] == i? 1: soe[i / soe[i]] + 1);
	for (int i = 3; i <= 5000000; i++)
		soe[i] += soe[i - 1];
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", soe[a] - soe[b]);
	}
	return 0;
}