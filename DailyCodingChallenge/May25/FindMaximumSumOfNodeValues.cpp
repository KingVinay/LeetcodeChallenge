#include<bits/stdc++.h>
using namespace std;

long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long maxSum = 0;
        int changedCount = 0;
        int minChangeDiff = INT_MAX;

        for (int num : nums) {
            maxSum += max(num, num ^ k);
            changedCount += ((num ^ k) > num) ? 1 : 0;
            minChangeDiff = min(minChangeDiff, abs(num - (num ^ k)));
        }

        if (changedCount % 2 == 0)
            return maxSum;
        return maxSum - minChangeDiff;
    }
    
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};

    long long result = maximumValueSum(nums, k, edges);
    cout << "Maximum sum of node values: " << result << endl;

    return 0;
}