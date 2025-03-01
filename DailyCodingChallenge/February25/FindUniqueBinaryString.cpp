#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(n)

string findDifferentBinaryString(vector<string>& nums) {
  int n = nums.size();
  string result = "";
  for (int i = 0; i < n; i++) {
      // Flip the i-th bit of the i-th string
      result += (nums[i][i] == '0') ? '1' : '0';
  }
  return result;
}

// Time Complexity: O(2^n)

string findDifferentBinaryString(vector<string>& nums) {
  int n = nums.size();
  unordered_set<int> st;

  for (int i = 0; i < n; i++) {
      int val = stoi(nums[i], nullptr, 2);
      st.insert(val);
  }

  int range = pow(2, n);
  string ans;
  for (int i = range-1;i>=0;i--) {
      if (st.find(i) != st.end()) {
          continue;
      } else {
          ans = bitset<16>(i).to_string().substr(16 - n);
          break;
      }
  }

  return ans;
}

int main()
{
    vector<string> nums = {"0011", "1011", "1111"};
    cout << findDifferentBinaryString(nums) << endl; // "0100"
    return 0;
}