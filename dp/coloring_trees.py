'''
	http://codeforces.com/contest/711/problem/C
'''

n, m, k = [int(x) for x in raw_input().split()]
c = [0] + [int(x) for x in raw_input().split()]
inf = float('inf')
dp = [[[inf for z in xrange(k + 1)] for y in xrange(m + 1)] for x in xrange(2)]
if c[1]:
	raw_input()
	dp[1][c[1]][1] = 0
	ms = [[inf, inf] for x in xrange(k + 1)]
	ms[1][0] = 0
else:
	p = [inf] + [int(x) for x in raw_input().split()]
	for j in xrange(1, m + 1):
		dp[1][j][1] = p[j]
	ms = [[inf, inf] for x in xrange(k + 1)]
	for j in xrange(1, m + 1):
		if p[j] < ms[1][0]:
			ms[1][0], ms[1][1] = p[j], ms[1][0]
		elif p[j] < ms[1][1]:
			ms[1][1] = p[j]
	
for i in xrange(2, n + 1):
	if c[i]:
		raw_input()
		dp[i % 2] = [[inf for z in xrange(k + 1)] for y in xrange(m + 1)]
		for l in xrange(1, k + 1):
			dp[i % 2][c[i]][l] = min(dp[1 - i % 2][c[i]][l], ms[l - 1][0] if ms[l - 1][0] != dp[1 - i % 2][c[i]][l - 1] else ms[l - 1][1])
	else:
		p = [inf] + [int(x) for x in raw_input().split()]
		for j in xrange(1, m + 1):
			for l in xrange(1, k + 1):
				dp[i % 2][j][l] = p[j] + min(dp[1 - i % 2][j][l], ms[l - 1][0] if ms[l - 1][0] != dp[1 - i % 2][j][l - 1] else ms[l - 1][1])
				
	ms = [[inf, inf] for x in xrange(k + 1)]
	for j in xrange(1, m + 1):
		for l in xrange(1, k + 1):
			if dp[i % 2][j][l] < ms[l][0]:
				ms[l][0], ms[l][1] = dp[i % 2][j][l], ms[l][0]
			elif dp[i % 2][j][l] < ms[l][1]:
				ms[l][1] = dp[i % 2][j][l]
				
ans = min([dp[n % 2][j][k] for j in xrange(1, m + 1)])
print ans if ans < inf else -1