#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct T {
  TreeNode* lca;
  int depth;
};

class Solution {
public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) { return dfs(root).lca; }

  T dfs(TreeNode* root) {
      if (root == NULL)
          return {NULL, 0};
      T left = dfs(root->left);
      T right = dfs(root->right);
      
      if (left.depth > right.depth)
          return {left.lca, left.depth + 1};
      if (left.depth < right.depth)
          return {right.lca, right.depth + 1};
      return {root, left.depth + 1};
  }
};

int main()
{
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  Solution s;
  TreeNode* lca = s.lcaDeepestLeaves(root);
  cout << "LCA of deepest leaves: " << lca->val << endl;


  return 0;
}