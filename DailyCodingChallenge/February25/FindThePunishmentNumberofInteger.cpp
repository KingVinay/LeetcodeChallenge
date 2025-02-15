#include<bits/stdc++.h>
using namespace std;

bool isPunishment(int acc, int run, string &s, int idx, int target){
  if(idx == s.length()){
      return (acc+run == target);
  }
  int num = s[idx] - '0';
  // Recursive Calls to split number eX:- 121=> 121, 1 21, 12 1, 1 2 1
  return isPunishment(acc, run*10 + num, s, idx+1, target) || 
         isPunishment(acc+run, num, s, idx+1, target);
}

int punishmentNumber(int n) {
  int ans = 0;
  for(int i=1;i<=n;i++){
      if(i%9 == 0 || i%9 == 1){
          string s = to_string(i*i);
          if(isPunishment(0,0,s,0,i)){
              ans += i*i;
          }
      }
  }
  return ans;
}

int main()
{
  int n;
  cin>>n;
  cout<<punishmentNumber(n)<<endl;
  return 0;
}