#include<bits/stdc++.h>
using namespace std;

int numTilings(int n) {
  int kMod = 1e9 + 7;
  vector<long> dp(1001);
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 5;

  for (int i = 4; i <= n; ++i)
      dp[i] = (2 * dp[i - 1] + dp[i - 3]) % kMod;

  return dp[n];
}

int main()
{
  int n = 9; // Example input
  int result = numTilings(n);
  cout << "Number of ways to tile a 2 x " << n << " board: " << result << endl;

  return 0;
}