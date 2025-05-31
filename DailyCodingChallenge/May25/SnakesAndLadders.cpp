#include<bits/stdc++.h>
using namespace std;

int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q{{1}};
        vector<bool> seen(1 + n * n);
        vector<int> arr(1 + n * n);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                arr[(n - 1 - i) * n + ((n - i) % 2 == 0 ? n - j : j + 1)] =
                    board[i][j];

        for (int step = 1; !q.empty(); ++step)
            for (int sz = q.size(); sz > 0; --sz) {
                int curr = q.front();
                q.pop();
                for (int next = curr + 1; next <= min(curr + 6, n * n);
                     ++next) {
                    int dest = arr[next] > 0 ? arr[next] : next;
                    if (dest == n * n)
                        return step;
                    if (seen[dest])
                        continue;
                    q.push(dest);
                    seen[dest] = true;
                }
            }

        return -1;
    }

int main()
{
    vector<vector<int>> board = {
        { -1, -1, -1, -1, -1, -1 },
        { -1, -1, -1, 2, 3, -1 },
        { -1, 4, -1, 5, 6, -1 },
        { 7, 8, 9, 10, 11, -1 },
        { -1, 12, 13, 14, 15, -1 },
        { -1, -1, -1, -1, -1, 16 }
    };

    int result = snakesAndLadders(board);
    cout << "Minimum number of moves to reach the end: " << result << endl;

    return 0;
}