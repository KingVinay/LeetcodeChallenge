#include<bits/stdc++.h>
using namespace std;

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
        : nums1(nums1), nums2(nums2) {
        for (const int num : nums2)
            ++count2[num];
    }

    void add(int index, int val) {
        --count2[nums2[index]];
        nums2[index] += val;
        ++count2[nums2[index]];
    }

    int count(int tot) {
        int ans = 0;
        for (const int num : nums1) {
            const int target = tot - num;
            if (const auto it = count2.find(target); it != count2.cend())
                ans += it->second;
        }
        return ans;
    }

private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> count2;
};

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {4, 5, 6};
    FindSumPairs fsp(nums1, nums2);

    cout << "Count of pairs with sum 7: " << fsp.count(7) << endl; // Output: 3
    fsp.add(0, 1); // nums2 becomes [5, 5, 6]
    cout << "Count of pairs with sum 7 after adding: " << fsp.count(7) << endl; // Output: 2

    return 0;
}