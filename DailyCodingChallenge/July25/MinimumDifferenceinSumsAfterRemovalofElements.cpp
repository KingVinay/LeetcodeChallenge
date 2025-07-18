#include<bits/stdc++.h>
using namespace std;

long long minimumDifference(vector<int>& nums) {
    int n = nums.size() / 3;
    long ans = LONG_MAX;
    long leftSum = 0;
    long rightSum = 0;

    priority_queue<int> maxHeap;

    priority_queue<int, vector<int>, greater<>> minHeap;

    vector<long> minLeftSum(nums.size());

    for (int i = 0; i < 2 * n; ++i) {
        maxHeap.push(nums[i]);
        leftSum += nums[i];
        if (maxHeap.size() == n + 1)
            leftSum -= maxHeap.top(), maxHeap.pop();
        if (maxHeap.size() == n)
            minLeftSum[i] = leftSum;
    }

    for (int i = nums.size() - 1; i >= n; --i) {
        minHeap.push(nums[i]);
        rightSum += nums[i];
        if (minHeap.size() == n + 1)
            rightSum -= minHeap.top(), minHeap.pop();
        if (minHeap.size() == n)
            ans = min(ans, minLeftSum[i - 1] - rightSum);
    }

    return ans;
}

int main(){
    vector<int> nums = {3, 1, 2, 4, 3, 5, 6, 7, 8};
    long long result = minimumDifference(nums);
    cout << "Minimum difference in sums after removal of elements: " << result << endl;

    return 0;
}