#include<bits/stdc++.h>
using namespace std;

int minimumDeletions(string word, int k) {
    int ans = INT_MAX;
    vector<int> count(26);

    for (char c : word)
        ++count[c - 'a'];

    for (int minFreq : count) {
        int deletions = 0;
        for (int freq : count)
            if (freq < minFreq)
                deletions += freq;
            else
                deletions += max(0, freq - (minFreq + k));
        ans = min(ans, deletions);
    }

    return ans;
}

int main()
{
  string word;
  int k;
  cin >> word >> k;

  int result = minimumDeletions(word, k);
  cout << result << endl;

  return 0;
}