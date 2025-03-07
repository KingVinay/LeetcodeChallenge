#include<bits/stdc++.h>
using namespace std;

// Solution using sieve of eratosthenes Time - O(n*log(log(n))) Space - O(n)
vector<int> closestPrimes(int left, int right) {
  vector<bool> isPrime(right + 1, true);
  vector<int> ans(2,-1);
  isPrime[0] = isPrime[1] = false;

  for (int p = 2; p * p <= right; p++) {
      if (isPrime[p]) {
          for (int i = p * p; i <= right; i += p) {
              isPrime[i] = false;
          }
      }
  }

  int p1 = -1, p2 = -1;
  int diff = INT_MAX;

  for (int i = left; i <= right; i++) {
      if (isPrime[i]) {
          if(p1 == -1) {
            p1 = i;
          }else if(p2 == -1) {
            p2 = i;
          }

          if (p1 != -1 && p2 != -1) {
              int d = p2 - p1;
              if (diff > d) {
                diff = d;
                ans[0] = p1;
                ans[1] = p2;
              }
              p1 = p2;
              p2 = -1;
          }
      }
  }
  
  return {ans[0], ans[1]};
}


// Solution using check prime and then diff of primes Time - O(n*sqrt(n)) Space - O(1)
bool checkprime(int n) {
  if (n <= 1) {
      return false;
  }

  for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) {
          return false;
      }
  }

  return true;
}

vector<int> closestPrimes(int left, int right) {
  vector<int> ans(2, -1);
  int p1 = -1, p2 = -1;
  int diff = INT_MAX;
  for (int i = left; i <= right; i++) {
      bool x = checkprime(i);
      if (x) {
          if (p1 == -1) {
              p1 = i;
          } else if (p2 == -1) {
              p2 = i;
          }
          if (p1 != -1 && p2 != -1) {
              int d = p2 - p1;
              if (diff > d) {
                  diff = d;
                  ans[0] = p1;
                  ans[1] = p2;
              }
              p1 = p2;
              p2 = -1;
          }
      }
  }
  return ans;
}

int main()
{
  int left = 10, right = 20;
  vector<int> result = closestPrimes(left, right);
  cout << "Closest prime numbers are: " << result[0] << " and " << result[1] << endl;
  return 0;
}