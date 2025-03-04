#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(log3(n))
bool checkPowersOfThree(int n) {
  while(n){
      if(n%3 == 2){
          return false;
      }
      n/=3;
  }
  return true;
}

// Time complexity: O(logn)
bool checkPowersOfThree(int n) {
  int mx = 1,cnt = 0;
  while(mx <= n){
      mx *= 3;
      cnt += 1;
  }

  cnt--;

  int ans = 0;
  bool res = 0;
  while(cnt>=0){
      ans += pow(3,cnt);
      if(ans == n){
          res = 1;
      }else if(ans > n){
          ans -= pow(3,cnt);
      }

      cnt --;
  }

  return res;
}

int main()
{
  int n = 12;
  cout<<checkPowersOfThree(n)<<endl;
  return 0;
}