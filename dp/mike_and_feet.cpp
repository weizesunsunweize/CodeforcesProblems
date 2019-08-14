/**
  * http://codeforces.com/contest/547/problem/B
  */

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, a[200007], l[200007], r[200007], ans[200007] = {0};
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int temp = i - 1;
		while (temp && a[temp] >= a[i]) temp = l[temp];
		l[i] = temp;
	}
	for (int i = n; i >= 1; i--) {
		int temp = i + 1;
		while (temp != n + 1 && a[temp] >= a[i]) temp = r[temp];
		r[i] = temp;
	}
	for (int i = 1; i <= n; i++)
		ans[r[i] - l[i] - 1] = max(ans[r[i] - l[i] - 1], a[i]);
 	for (int i = n - 1; i >= 1; i--)
		ans[i] = max(ans[i], ans[i + 1]);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}