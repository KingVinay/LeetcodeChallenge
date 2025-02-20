#include<bits/stdc++.h>
using namespace std;

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
{}