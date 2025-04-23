#include<bits/stdc++.h>
using namespace std;

int countLargestGroup(int n) {
  vector<int> count(9 * 4 + 1);
  for (int i = 1; i <= n; ++i)
      ++count[getDigitSum(i)];
  return ranges::count(count, ranges::max(count));
}

int getDigitSum(int num) {
  int digitSum = 0;
  while (num > 0) {
      digitSum += num % 10;
      num /= 10;
  }
  return digitSum;
}

int main()
{
  int n = 13;
  int result = countLargestGroup(n);
  cout << "The number of groups with the largest size is: " << result << endl;
  return 0;
}