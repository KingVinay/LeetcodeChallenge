#include<bits/stdc++.h>
using namespace std;

int countHillValley(vector<int>& nums) {
        int ans = 0;
        int left = nums[0];

        for (int i = 1; i + 1 < nums.size(); ++i)
            if (left < nums[i] && nums[i] > nums[i + 1] ||
                left > nums[i] && nums[i] < nums[i + 1]) {
                ++ans;
                left = nums[i];
            }

        return ans;
    }

int main()
{
    vector<int> nums = {2, 4, 1, 1, 6, 5};
    cout << "Number of Hills and Valleys: " << countHillValley(nums) << endl;
    return 0;
}