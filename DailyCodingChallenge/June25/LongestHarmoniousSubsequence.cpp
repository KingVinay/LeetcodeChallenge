#include<bits/stdc++.h>
using namespace std;

int findLHS(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> count;

    for (int num : nums)
        ++count[num];

    for (auto& [num, freq] : count)
        if (auto it = count.find(num + 1); it != count.cend())
            ans = max(ans, freq + it->second);

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 2, 2, 5, 4, 3, 3};
    int result = findLHS(nums);
    
    cout << "Length of the longest harmonious subsequence: " << result << endl;

    return 0;
}

