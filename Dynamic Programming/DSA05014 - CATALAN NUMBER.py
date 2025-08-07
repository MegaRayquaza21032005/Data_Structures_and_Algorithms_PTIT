from math import *
mod = (int) (1e9 + 7)

dp = [0] * 109

def Catalan_number():
  dp[0] = 1
  for i in range(1, 101):
    for j in range(0, i):
      dp[i] += dp[j] * dp[i - j - 1]

#main

Catalan_number()
T = int(input())
while T > 0:
  T -= 1
  n = int(input())
  if n == 0: print(0)
  else: print(dp[n])