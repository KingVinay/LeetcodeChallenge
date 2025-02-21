#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class FindElements {
  public:
      FindElements(TreeNode* root) { dfs(root, 0); }
  
      bool find(int target) { return vals.contains(target); }
  
  private:
      unordered_set<int> vals;
  
      void dfs(TreeNode* root, int val) {
          if (root == nullptr)
              return;
  
          root->val = val;
          vals.insert(val);
          dfs(root->left, val * 2 + 1);
          dfs(root->right, val * 2 + 2);
      }
};
int main()
{
  TreeNode* root = new TreeNode(-1);
  root->left = new TreeNode(-1);
  root->right = new TreeNode(-1);
  root->left->left = new TreeNode(-1);
  root->left->right = new TreeNode(-1);
  root->right->left = new TreeNode(-1);
  root->right->right = new TreeNode(-1);

  FindElements findElements(root);
  cout << findElements.find(4) << endl; // true
  cout << findElements.find(5) << endl; // false
  return 0;
}