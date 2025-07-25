#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int>& nums) {
        int mx = ranges::max(nums);
        if (mx <= 0)
            return mx;
        unordered_set<int> numsSet(nums.begin(), nums.end());
        return accumulate(numsSet.begin(), numsSet.end(), 0,
                          [](int acc, int num) { return acc + max(0, num); });
    }

int main()
{
    vector<int> nums = {4, 2, -1, 3, 5, -2};
    cout << "Maximum Unique Subarray Sum After Deletion: " << maxSum(nums) << endl;
    return 0; 
}