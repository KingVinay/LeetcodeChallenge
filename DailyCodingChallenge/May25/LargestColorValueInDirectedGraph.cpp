#include<bits/stdc++.h>
using namespace std;

int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        int ans = 0;
        int processed = 0;
        vector<vector<int>> graph(n);
        vector<int> inDegrees(n);
        queue<int> q;
        vector<vector<int>> count(n, vector<int>(26));

        // Build the graph.
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            ++inDegrees[v];
        }

        // Perform topological sorting.
        for (int i = 0; i < n; ++i)
            if (inDegrees[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int out = q.front();
            q.pop();
            ++processed;
            ans = max(ans, ++count[out][colors[out] - 'a']);
            for (int in : graph[out]) {
                for (int i = 0; i < 26; ++i)
                    count[in][i] = max(count[in][i], count[out][i]);
                if (--inDegrees[in] == 0)
                    q.push(in);
            }
        }

        return processed == n ? ans : -1;
    }

int main()
{
    string colors = "abaca";
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}};
    int result = largestPathValue(colors, edges);
    cout << "Largest color value in the directed graph: " << result << endl;

    return 0;
}