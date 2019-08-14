'''
http://codeforces.com/contest/559/problem/B
'''

#!/usr/bin/env python
def dc(s):
	if len(s) % 2:
		return s
	s1, s2 = dc(s[:len(s) / 2]), dc(s[len(s) / 2:])
	return min(s1 + s2, s2 + s1)
print "YES" if dc(raw_input()) == dc(raw_input()) else "NO"