#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; ++i)
        ans.push_back(vector<int>(i + 1, 1));

    for (int i = 2; i < numRows; ++i)
        for (int j = 1; j < ans[i].size() - 1; ++j)
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];

    return ans;
}

int main()
{
    int numRows = 5;
    vector<vector<int>> result = generate(numRows);
    
    cout << "Pascal's Triangle up to " << numRows << " rows:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}