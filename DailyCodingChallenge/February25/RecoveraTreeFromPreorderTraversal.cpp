#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* recoverFromPreorder(string S) {
  stack<TreeNode*> st;
  int depth = 0;
  int num = 0;
  for (int i = 0; i < S.length(); ++i) {
      if (S[i] == '-') {
          depth++;
      } else {
          num = 10 * num + S[i] - '0';
      }
      if (i + 1 >= S.length() || (isdigit(S[i]) && S[i + 1] == '-')) {
          TreeNode* newNode = new TreeNode(num);
          while (st.size() > depth) {
              st.pop();
          }
          if (!st.empty()) {
              if (st.top()->left == nullptr) {
                  st.top()->left = newNode;
              } else {
                  st.top()->right = newNode;
              }
          }
          st.push(newNode);
          depth = 0;
          num = 0;
      }
  }
  TreeNode* res;
  while (!st.empty()) {
      res = st.top();
      st.pop();
  }
  return res;
}

int main()
{
  string s = "1-2--3---4-5--6---7";
  TreeNode* root = recoverFromPreorder(s);
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
  cout << endl;
  return 0;
}