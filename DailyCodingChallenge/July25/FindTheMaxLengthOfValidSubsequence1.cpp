#include<bits/stdc++.h>
using namespace std;

int maximumLength(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(2));

        for (const int x : nums)
            for (int y = 0; y < 2; ++y)
                dp[x % 2][y] = dp[y][x % 2] + 1;

        return accumulate(dp.begin(), dp.end(), 0,
                          [](int acc, const vector<int>& row) {
                              return max(acc, ranges::max(row));
                          });
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result = maximumLength(nums);
    cout << "Maximum length of valid subsequence: " << result << endl;

    return 0;
}