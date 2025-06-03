#include<bits/stdc++.h>
using namespace std;

int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int ans = 0;
        queue<int> q;
        vector<bool> reachedClosedBoxes(status.size());

        auto pushBoxesIfPossible =
            [&status, &q, &reachedClosedBoxes](const vector<int>& boxes) {
                for (const int box : boxes)
                    if (status[box])
                        q.push(box);
                    else
                        reachedClosedBoxes[box] = true;
            };

        pushBoxesIfPossible(initialBoxes);

        while (!q.empty()) {
            const int currBox = q.front();
            q.pop();

            ans += candies[currBox];

            for (const int key : keys[currBox]) {
                if (!status[key] && reachedClosedBoxes[key])
                    q.push(key);
                status[key] = 1;
            }

            pushBoxesIfPossible(containedBoxes[currBox]);
        }

        return ans;
    }int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int ans = 0;
        queue<int> q;
        vector<bool> reachedClosedBoxes(status.size());

        auto pushBoxesIfPossible =
            [&status, &q, &reachedClosedBoxes](const vector<int>& boxes) {
                for (const int box : boxes)
                    if (status[box])
                        q.push(box);
                    else
                        reachedClosedBoxes[box] = true;
            };

        pushBoxesIfPossible(initialBoxes);

        while (!q.empty()) {
            const int currBox = q.front();
            q.pop();

            ans += candies[currBox];

            for (const int key : keys[currBox]) {
                if (!status[key] && reachedClosedBoxes[key])
                    q.push(key);
                status[key] = 1;
            }

            pushBoxesIfPossible(containedBoxes[currBox]);
        }

        return ans;
    }

int main()
{
    vector<int> status = {1, 0, 1, 0, 1};
    vector<int> candies = {5, 10, 15, 20, 25};
    vector<vector<int>> keys = {{}, {0}, {}, {1}, {}};
    vector<vector<int>> containedBoxes = {{1}, {}, {3}, {}, {}};
    vector<int> initialBoxes = {0};

    int result = maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    cout << "Maximum candies you can get: " << result << endl;

    return 0;
}