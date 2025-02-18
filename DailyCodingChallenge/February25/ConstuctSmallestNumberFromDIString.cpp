#include<bits/stdc++.h>
using namespace std;

string smallestNumber(string pattern) {
  string ans = "";
  stack<char> st{{'1'}};
  for(int i=0;i<pattern.length();i++){
      char mx = st.top();
      if(pattern[i] == 'I'){
          while(!st.empty()){
              ans += st.top();
              mx = max(mx,st.top());
              st.pop();
          }
      }
      st.push(mx+1);
  }

  while(!st.empty()){
      ans += st.top();
      st.pop();
  }

  return ans;
}

int main()
{
  string pattern = "IIIDIDDD";
  cout << smallestNumber(pattern) << endl; // "13254"
  return 0;
}