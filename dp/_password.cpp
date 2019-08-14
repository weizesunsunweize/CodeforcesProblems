/**
  * http://codeforces.com/contest/126/problem/B
  * KPM algorithm
  */

#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	vector<int> p(s.size() + 1, 0);
	p[0] = -1;
	for (int i = 1; i <= s.size(); i++) {
		int k = p[i - 1];
		while (k >= 0 && s[k] != s[i - 1]) 
			k = p[k];
		p[i] = k + 1;
	}
	for (int i = 0; i < s.size(); i++)
		if (p[i] && p[i] == p[s.size()]) {
			cout << s.substr(0, p[s.size()]) << endl;
			return 0;
		}
	if (p[p[s.size()]] > 0) {
		cout << s.substr(0, p[p[s.size()]]) << endl;
		return 0;
	}
	cout << "Just a legend" << endl;
	return 0;
}