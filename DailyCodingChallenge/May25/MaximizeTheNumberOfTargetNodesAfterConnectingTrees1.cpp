#include<bits/stdc++.h>
using namespace std;

vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        vector<int> ans;
        vector<vector<int>> graph1 = buildGraph(edges1);
        vector<vector<int>> graph2 = buildGraph(edges2);
        int maxReachableInGraph2 = 0;

        if (k > 0)
            for (int i = 0; i < edges2.size() + 1; ++i)
                maxReachableInGraph2 =
                    max(maxReachableInGraph2, dfs(graph2, i, -1, k - 1));

        for (int i = 0; i < edges1.size() + 1; ++i)
            ans.push_back(maxReachableInGraph2 + dfs(graph1, i, -1, k));

        return ans;
    }

    int dfs(vector<vector<int>>& graph, int u, int prev, int k) {
        if (k == 0)
            return 1;
        int res = 0;
        for (int v : graph[u])
            if (v != prev)
                res += dfs(graph, v, u, k - 1);
        return 1 + res;
    }

    vector<vector<int>> buildGraph(vector<vector<int>>& edges) {
        vector<vector<int>> graph(edges.size() + 1);
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return graph;
    }

int main()
{
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}};
    int k = 2;

    vector<int> result = maxTargetNodes(edges1, edges2, k);
    cout << "Maximize the number of target nodes after connecting trees: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}