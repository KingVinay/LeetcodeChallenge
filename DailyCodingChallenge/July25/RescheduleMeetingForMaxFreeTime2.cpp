#include<bits/stdc++.h>
using namespace std;

int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps = getGaps(eventTime, startTime, endTime);
        int ans = 0;
        vector<int> maxLeft(n + 1);
        vector<int> maxRight(n + 1);

        maxLeft[0] = gaps[0];
        maxRight[n] = gaps[n];

        for (int i = 1; i < n + 1; ++i)
            maxLeft[i] = max(gaps[i], maxLeft[i - 1]);

        for (int i = n - 1; i >= 0; --i)
            maxRight[i] = max(gaps[i], maxRight[i + 1]);

        for (int i = 0; i < n; ++i) {
            int currMeetingTime = endTime[i] - startTime[i];
            int adjacentGapsSum = gaps[i] + gaps[i + 1];
            bool canMoveMeeting =
                currMeetingTime <= max(i > 0 ? maxLeft[i - 1] : 0,
                                       i + 2 < n + 1 ? maxRight[i + 2] : 0);
            ans = max(ans,
                      adjacentGapsSum + (canMoveMeeting ? currMeetingTime : 0));
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

    int result = maxFreeTime(eventTime, startTime, endTime);
    cout << "Maximum free time available: " << result << endl;

    return 0;
}