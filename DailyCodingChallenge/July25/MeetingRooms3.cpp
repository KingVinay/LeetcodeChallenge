#include<bits/stdc++.h>
using namespace std;

int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> roomEndTime(n, 0);
        vector<int> count(n, 0);
        priority_queue<int, vector<int>, greater<>> available;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            busy;

        for (auto& meet : meetings) {
            long long start = meet[0], end = meet[1];

            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();
                roomEndTime[room] = end;
                count[room]++;
                busy.push({end, room});
            } else {
                auto [endTime, room] = busy.top();
                busy.pop();
                roomEndTime[room] = endTime + (end - start);
                count[room]++;
                busy.push({roomEndTime[room], room});
            }
        }

        int maxRoom = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[maxRoom]) {
                maxRoom = i;
            }
        }
        return maxRoom;
    }

int main()
{
    int n = 3; // Number of rooms
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}, {8, 9}};

    int result = mostBooked(n, meetings);
    cout << "Room with the most bookings: " << result << endl;

    return 0;
}