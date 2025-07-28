#include<bits/stdc++.h>
using namespace std;

int countMaxOrSubsets(vector<int>& nums) {
        int ors = accumulate(nums.begin(), nums.end(), 0, bit_or<>());
        int ans = 0;
        dfs(nums, 0, 0, ors, ans);
        return ans;
    }

    void dfs(vector<int>& nums, int i, int path, int& ors, int& ans) {
        if (i == nums.size()) {
            if (path == ors)
                ++ans;
            return;
        }

        dfs(nums, i + 1, path, ors, ans);
        dfs(nums, i + 1, path | nums[i], ors, ans);
    }

int main()
{
    vector<int> nums = {3, 1, 5, 7};
    cout << "Count of Maximum Bitwise OR Subsets: " << countMaxOrSubsets(nums) << endl;
    return 0;
}