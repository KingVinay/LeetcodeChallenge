#include<bits/stdc++.h>
using namespace std;

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto g1 = build(edges1);
        auto g2 = build(edges2);
        int n = g1.size(), m = g2.size();
        vector<int> c1(n, 0), c2(m, 0);
        vector<int> cnt1(2, 0), cnt2(2, 0);

        dfs(g2, 0, -1, c2, 0, cnt2);
        dfs(g1, 0, -1, c1, 0, cnt1);

        int t = max(cnt2[0], cnt2[1]);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = t + cnt1[c1[i]];
        }
        return ans;
    }

    vector<vector<int>> build(const vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        return g;
    }

    void dfs(const vector<vector<int>>& g, int a, int fa, vector<int>& c, int d, vector<int>& cnt) {
        c[a] = d;
        cnt[d]++;
        for (int b : g[a]) {
            if (b != fa) {
                dfs(g, b, a, c, d ^ 1, cnt);
            }
        }
    }

int main()
{
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}};

    vector<int> result = maxTargetNodes(edges1, edges2);
    cout << "Maximize the number of target nodes after connecting trees: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}