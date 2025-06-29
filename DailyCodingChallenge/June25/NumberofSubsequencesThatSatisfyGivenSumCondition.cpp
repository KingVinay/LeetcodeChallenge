#include<bits/stdc++.h>
using namespace std;

int numSubseq(vector<int>& nums, int target) {
        int kMod = 1'000'000'007;
        int n = nums.size();
        int ans = 0;
        vector<int> pows(n, 1);

        for (int i = 1; i < n; ++i)
            pows[i] = pows[i - 1] * 2 % kMod;

        ranges::sort(nums);

        for (int l = 0, r = n - 1; l <= r;)
            if (nums[l] + nums[r] <= target) {
                ans += pows[r - l];
                ans %= kMod;
                ++l;
            } else {
                --r;
            }

        return ans;
    }

int main()
{
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;
    int result = numSubseq(nums, target);
    
    cout << "Number of subsequences that satisfy the given sum condition: " << result << endl;

    return 0;
}