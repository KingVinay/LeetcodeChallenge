#include<bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int>& nums) {
  unordered_set<int> s;
  for (int i = nums.size() - 1; i>=0; --i) {
      if (s.contains(nums[i])) {
          return i / 3 + 1;
      }
      s.insert(nums[i]);
  }
  return 0;
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  int result = minimumOperations(nums);
  cout << "Minimum number of operations to make elements distinct: " << result << endl;

  return 0;
}