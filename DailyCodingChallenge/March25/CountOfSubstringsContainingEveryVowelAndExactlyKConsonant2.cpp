#include<bits/stdc++.h>
using namespace std;

bool vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long VC(string& word, int k) {
  long long ans = 0;
  int left = 0, consonantcnt = 0;
  unordered_map<char, int> vowelcnt;
  for (char c : word) {
      if (vowel(c)) {
          vowelcnt[c]++;
      } else {
          ++consonantcnt;
      }
      while (consonantcnt >= k && vowelcnt.size() == 5) {
          char d = word[left++];
          if (vowel(d)) {
              if (--vowelcnt[d] == 0) {
                  vowelcnt.erase(d);
              }
          } else {
              --consonantcnt;
          }
      }
      ans += left;
  }
  return ans;
}

long long countOfSubstrings(string word, int k) {
  return VC(word, k) - VC(word, k + 1);
}

int main()
{
  string word = "abciiidef";
  int k = 3;
  cout<<countOfSubstrings(word,k)<<endl;
  return 0;
}