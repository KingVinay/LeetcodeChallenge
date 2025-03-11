#include<bits/stdc++.h>
using namespace std;

// Using Last Seen

int numberOfSubstrings(string s) {
  int num = 0, a = -1, b = -1, c = -1;
  for(int i = 0; i<s.length() ; i++){
      if(s[i] == 'a') a = i;
      if(s[i] == 'b') b = i;
      if(s[i] == 'c') c = i;
      if(a != -1 && b != -1 && c != -1)
      num += min(a,min(b,c)) + 1;   
  }
  return num;
}

// Using Sliding Window 
int numberOfSubstrings(string s) {
  int ans = 0,left = 0;
  vector<int> cnt(3,0);
  for(char c: s){
      cnt[c - 'a']++;

      while(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0){
          --cnt[s[left++] - 'a'];
      }

      ans+= left;
  }

  return ans;
}

int main()
{
  string s = "abcabc";
  cout<<numberOfSubstrings(s)<<endl;
  return 0;
}