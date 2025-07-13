#include<bits/stdc++.h>
using namespace std;

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans = 0;

        ranges::sort(players);
        ranges::sort(trainers);

        for (int i = 0; i < trainers.size(); ++i)
            if (players[ans] <= trainers[i] && ++ans == players.size())
                return ans;

        return ans;
}

int main()
{
    vector<int> players = {4, 7, 9, 2, 5};
    vector<int> trainers = {8, 3, 6, 10, 1};

    int result = matchPlayersAndTrainers(players, trainers);
    cout << "Maximum number of players that can be matched with trainers: " << result << endl;

    return 0;
}