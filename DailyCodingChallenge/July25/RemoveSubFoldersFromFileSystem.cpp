#include<bits/stdc++.h>
using namespace std;

vector<string> removeSubfolders(vector<string>& folder) {
    vector<string> ans;
    string prev;

    ranges::sort(folder);

    for (string& f : folder) {
        if (!prev.empty() && f.find(prev) == 0 && f[prev.length()] == '/')
            continue;
        ans.push_back(f);
        prev = f;
    }

    return ans;
}

int main()
{
    vector<string> folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    vector<string> result = removeSubfolders(folder);
    
    cout << "Remaining folders after removing subfolders: ";
    for (const string& f : result) {
        cout << f << " ";
    }
    cout << endl;

    return 0;
}