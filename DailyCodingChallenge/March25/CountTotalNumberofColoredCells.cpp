#include<bits/stdc++.h>
using namespace std;

// Using Direct Arithmetic
long long coloredCells(int n) {
  long long ans = 1;
  ans += 2 * n * (n-1);
  return ans;
}

// Using Pow function
long long coloredCells(int n) {
  if(n==1){
      return 1;
  }
  long long ans;
  ans = pow(n-1,2) + pow(n,2);
  return ans;
}

int main()
{
  int n;
  cin >> n;
  cout << coloredCells(n) << endl;
  return 0;
}