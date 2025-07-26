#include<bits/stdc++.h>
using namespace std;

long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long validSubarrays = 0;
        int maxLeft = 0;
        int secondMaxLeft = 0;

        vector<long> gains(n + 1);
        vector<vector<int>> conflicts(n + 1);

        for (vector<int>& pair : conflictingPairs) {
            int a = pair[0];
            int b = pair[1];
            conflicts[max(a, b)].push_back(min(a, b));
        }

        for (int right = 1; right <= n; ++right) {
            for (int left : conflicts[right]) {
                if (left > maxLeft) {
                    secondMaxLeft = maxLeft;
                    maxLeft = left;
                } else if (left > secondMaxLeft) {
                    secondMaxLeft = left;
                }
            }

            validSubarrays += right - maxLeft;

            gains[maxLeft] += maxLeft - secondMaxLeft;
        }

        return validSubarrays + ranges::max(gains);
    }

int main()
{
    int n = 5;
    vector<vector<int>> conflictingPairs = {{1, 2}, {2, 3}, {4, 5}};
    cout << "Maximum Subarrays After Removing One Conflicting Pair: " 
         << maxSubarrays(n, conflictingPairs) << endl;
    return 0;
}