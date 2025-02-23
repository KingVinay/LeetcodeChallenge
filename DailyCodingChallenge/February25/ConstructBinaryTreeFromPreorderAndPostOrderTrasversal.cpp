#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

unordered_map<int,int> postorderidx;

    TreeNode* BuildTree(vector<int> preorder, int prestart, int preend, vector
    <int> postorder, int poststart, int postend){
        if(prestart > preend){return NULL;}

        TreeNode* root = new TreeNode(preorder[prestart]);

        if(prestart == preend){
            return root;
        }

        int leftrootidx = postorderidx[preorder[prestart+1]];
        int subtreelen = leftrootidx - poststart + 1;

        root->left = BuildTree(preorder, prestart+1, prestart + subtreelen, postorder, poststart, leftrootidx);
        root->right = BuildTree(preorder, prestart + subtreelen + 1, preend, postorder, leftrootidx + 1, postend - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++){
            postorderidx[postorder[i]] = i;
        }

        return BuildTree(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
    }

int main()
{
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};
    TreeNode* root = constructFromPrePost(preorder, postorder);
    // Print the tree in in-order traversal
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (true) {
        while (curr!= nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        if (st.empty()) break;
        curr = st.top();
        st.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
    return 0;
}