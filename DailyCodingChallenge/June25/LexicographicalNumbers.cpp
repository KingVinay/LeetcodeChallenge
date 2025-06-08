#include<bits/stdc++.h>
using namespace std;

vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int curr = 1;

        while (ans.size() < n) {
            ans.push_back(curr);
            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                while (curr % 10 == 9 || curr == n)
                    curr /= 10;
                ++curr;
            }
        }

        return ans;
    }

int main()
{
    int n;
    cin >> n;

    vector<int> result = lexicalOrder(n);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}