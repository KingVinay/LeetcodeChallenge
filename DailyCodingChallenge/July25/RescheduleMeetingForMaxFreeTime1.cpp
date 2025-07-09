#include<bits/stdc++.h>
using namespace std;

int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> gaps = getGaps(eventTime, startTime, endTime);
        int windowSum = accumulate(gaps.begin(), gaps.begin() + k + 1, 0);
        int ans = windowSum;

        for (int i = k + 1; i < gaps.size(); ++i) {
            windowSum += gaps[i] - gaps[i - k - 1];
            ans = max(ans, windowSum);
        }

        return ans;
    }

    vector<int> getGaps(int eventTime, vector<int>& startTime,
                        vector<int>& endTime) {
        vector<int> gaps{startTime[0]};
        for (int i = 1; i < startTime.size(); ++i)
            gaps.push_back(startTime[i] - endTime[i - 1]);
        gaps.push_back(eventTime - endTime.back());
        return gaps;
    }

int main()
{
    int eventTime = 10;
    vector<int> startTime = {1, 3, 5};
    vector<int> endTime = {2, 4, 6};
    int k = 1;

    int result = maxFreeTime(eventTime, k, startTime, endTime);
    cout << "Maximum free time available: " << result << endl;

    return 0;
}