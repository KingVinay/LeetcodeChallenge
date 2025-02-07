#include<bits/stdc++.h>
using namespace std;

vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    unordered_map<int,int> ball,color;
    vector<int> ans;
    for(int i=0;i<queries.size();i++){
        int b = queries[i][0];
        int c = queries[i][1];

        color[c]++;

        if(ball.contains(b) && --color[ball[b]] == 0){
            color.erase(ball[b]);
        }
        ball[b] = c;

        ans.push_back(color.size());
    }

    return ans;
}
int main()
{
    vector<vector<int>> queries = {{1,2},{2,3},{3,4},{4,5}};
    vector<int> ans = queryResults(4,queries);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}