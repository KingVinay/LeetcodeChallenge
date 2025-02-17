#include<bits/stdc++.h>
using namespace std;

int possibleseq(vector<int>& count) {
  int ans = 0;
  for (int i = 0; i < 26; ++i) {
      if (count[i] > 0) {
          --count[i];
          ans += 1 + possibleseq(count);
          ++count[i];
      }
  }
  return ans;
}
int numTilePossibilities(string tiles) {
  vector<int> count(26,0);
  for (char c : tiles) {
      ++count[c - 'A'];
  }
  return possibleseq(count);
}

int main()
{
  string tiles = "AABBC";
  cout << numTilePossibilities(tiles) << endl; //89
  return 0;
}