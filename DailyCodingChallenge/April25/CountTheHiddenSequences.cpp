#include<bits/stdc++.h>
using namespace std;

int numberOfArrays(vector<int>& differences, int lower, int upper) {
  vector<long> prefix(differences.size() + 1);

  for (int i = 0; i < differences.size(); ++i)
      prefix[i + 1] += prefix[i] + differences[i];

  long mx = ranges::max(prefix);
  long mn = ranges::min(prefix);
  return max(0L, (upper - lower) - (mx - mn) + 1);
}

int main()
{
  vector<int> differences = {1, -3, 4};
  int lower = 1;
  int upper = 6;
  int result = numberOfArrays(differences, lower, upper);
  cout << "Number of hidden sequences: " << result << endl;

  return 0;
}