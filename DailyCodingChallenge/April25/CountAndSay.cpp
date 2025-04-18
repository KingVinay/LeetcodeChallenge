#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
  string ans = "1";

  while (--n > 0) {
      string next;
      for (int i = 0; i < ans.length(); ++i) {
          int count = 1;
          while (i + 1 < ans.length() && ans[i] == ans[i + 1]) {
              ++count;
              ++i;
          }
          next += to_string(count) + ans[i];
      }
      ans = move(next);
  }

  return ans;
}

int main()
{
  int n = 5; // Example input
  string result = countAndSay(n);
  cout << "The " << n << "th term in the count-and-say sequence is: " << result << endl;

  return 0;
}