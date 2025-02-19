#include<bits/stdc++.h>
using namespace std;

void combination(vector<string>& strings, string curr, int len) {
  if (curr.size() == len) {
      strings.push_back(curr);
      return;
  }

  for (char nxt = 'a'; nxt <= 'c'; nxt++) {
      if (!curr.empty() && curr.back() == nxt) {
          continue;
      }
      curr.push_back(nxt);
      combination(strings, curr, len);
      curr.pop_back();
  }
}

string getHappyString(int n, int k) {
  vector<string> strings;
  combination(strings, "", n);

  return (strings.size() < k) ? "" : strings[k - 1];
}

int main()
{
  int n, k;
  cin>>n>>k;
  cout<<getHappyString(n, k)<<endl;
  return 0;
}