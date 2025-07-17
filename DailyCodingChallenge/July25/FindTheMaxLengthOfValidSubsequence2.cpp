#include<bits/stdc++.h>
using namespace std;

int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k));

        for (int x : nums)
            for (int y = 0; y < k; ++y)
                dp[x % k][y] = dp[y][x % k] + 1;

        return accumulate(dp.begin(), dp.end(), 0,
                          [](int acc, vector<int>& row) {
                              return max(acc, ranges::max(row));
                          });
    }

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 3; // Example value for k
    int result = maximumLength(nums, k);
    cout << "Maximum length of valid subsequence: " << result << endl;

    return 0;
}