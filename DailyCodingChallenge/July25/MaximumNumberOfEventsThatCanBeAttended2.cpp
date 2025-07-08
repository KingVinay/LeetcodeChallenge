#include<bits/stdc++.h>
using namespace std;

int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>> mem(events.size(), vector<int>(k + 1, -1));
        ranges::sort(events);
        return maxValue(events, 0, k, mem);
    }

    int maxValue(vector<vector<int>>& events, int i, int k,
                 vector<vector<int>>& mem) {
        if (k == 0 || i == events.size())
            return 0;
        if (mem[i][k] != -1)
            return mem[i][k];

        auto it = upper_bound(
            events.begin() + i, events.end(), events[i][1],
            [](int end, vector<int>& event) { return event[0] > end; });
        const int j = distance(events.begin(), it);
        return mem[i][k] = max(events[i][2] + maxValue(events, j, k - 1, mem),
                               maxValue(events, i + 1, k, mem));
    }

int main()
{
    vector<vector<int>> events = {{1, 2, 50}, {2, 3, 60}, {3, 4, 70}, {1, 2, 30}};
    int k = 2; // Maximum number of events to attend
    int result = maxValue(events, k);
    cout << "Maximum value of events that can be attended: " << result << endl; // Output: 110
    return 0;
}