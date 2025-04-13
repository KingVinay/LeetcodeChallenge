#include<bits/stdc++.h>
using namespace std;

int countGoodNumbers(long long n) {
  return modPow(4 * 5, n / 2) * (n % 2 == 0 ? 1 : 5) % kMod;
}

int kMod = 1000000007;

long modPow(long x, long n) {
  if (n == 0)
      return 1;
  if (n % 2 == 1)
      return x * modPow(x, n - 1) % kMod;
  return modPow(x * x % kMod, n / 2);
}

int main()
{
  long long n = 3;

  int result = countGoodNumbers(n);
  cout << "Count of good numbers: " << result << endl;

  return 0;
}