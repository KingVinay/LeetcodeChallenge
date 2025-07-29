#include<bits/stdc++.h>
using namespace std;

vector<int> smallestSubarrays(vector<int>& nums) {
        int kMaxBit = 30;
        vector<int> ans(nums.size(), 1);
        vector<int> closest(kMaxBit);

        for (int i = nums.size() - 1; i >= 0; --i)
            for (int j = 0; j < kMaxBit; ++j) {
                if (nums[i] >> j & 1)
                    closest[j] = i;
                ans[i] = max(ans[i], closest[j] - i + 1);
            }

        return ans;
    }

int main()
{
    vector<int> nums = {1, 2, 3, 2, 1};
    vector<int> result = smallestSubarrays(nums);
    
    cout << "Smallest Subarrays with Maximum Bitwise OR: ";
    for (int len : result) {
        cout << len << " ";
    }
    cout << endl;
    
    return 0;
}