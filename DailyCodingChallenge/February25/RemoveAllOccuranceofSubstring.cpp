#include<bits/stdc++.h>
using namespace std;

// Using find function
string removeOccurrences(string s, string part) {
  while(s.length()>0 && s.length()>s.find(part)){
     s.erase(s.find(part),part.length());
  }
  return s;
}

// Using sliding window
string removeOccurrences(string s, string part) {
  int n = part.length();
  int i=0,j=n-1;

  string temp = s.substr(i,j+1);
  cout<<temp<<endl;
  j++;
  i++;

  while(j<s.length()){
      if(temp == part){
          s.erase(s.begin()+i-1,s.begin()+j);
          cout<<s<<endl;
          i = 0;
          j = n - 1;
          temp = s.substr(i,j+1);
      }else{
          temp = s.substr(i,n);
      }
      i++;
      j++;
  }

  if(temp == part){
      s.erase(s.begin()+i-1,s.begin()+j);
  }

  return s;
}

int main()
{
  string s = "Hello, world! How are you today?";
  string part = "o";
  cout << removeOccurrences(s, part) << endl;
  return 0;
}