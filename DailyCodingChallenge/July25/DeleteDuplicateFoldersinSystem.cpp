#include<bits/stdc++.h>
using namespace std;

    struct Node{
        string name = "";
        map<string, Node*> next;
        bool del = false;
        Node(string s = ""):name(s){}
    };
    void addPath(Node* node, vector<string>& path){
        for(auto &s: path){
            if(node->next.count(s) == 0){
                node->next[s] = new Node(s);
            }
            node = node->next[s];
        }
    }

    unordered_map<string, Node*> seen;
    string removeDuplicate(Node* node){
        string subfolder = "";
        for(auto& [name, next]:node->next){
            subfolder += removeDuplicate(next);
        }
        if(!subfolder.empty()){
            if(seen.count(subfolder) == 0){
                seen[subfolder] = node;
            }else{
                seen[subfolder]->del = node->del = true;
            }
        }
        return "(" + node->name + subfolder + ")";
    }

    vector<vector<string>> ans;
    vector<string> path;
    void getPath(Node* node){
        if(node->del) return ;
        path.push_back(node->name);
        ans.push_back(path);
        for(auto& [name, next]:node->next){
            getPath(next);
        }
        path.pop_back();
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();
        for(auto& path:paths){
            addPath(root, path);
        }
        removeDuplicate(root);
        for(auto& [name, next]:root->next){
            getPath(next);
        }
        return ans;
    }

int main()
{
    vector<vector<string>> paths = { {"/a"}, {"/a/b"}, {"/c/d"}, {"/c/d/e"}, {"/c/f"} };
    vector<vector<string>> result = deleteDuplicateFolder(paths);
    
    cout << "Remaining folders after removing duplicates: " << endl;
    for (const auto& folder : result) {
        for (const string& f : folder) {
            cout << f << " ";
        }
        cout << endl;
    }

    return 0;
}