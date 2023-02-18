#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct TreeNode
{
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
 vector<int> nodes;
 void inorder(TreeNode *root)
 {
  if (root->left != NULL)
  {
   inorder(root->left);
  }
  nodes.push_back(root->val);
  if (root->right != NULL)
  {
   inorder(root->right);
  }
  return;
 }
 int minDiffInBST(TreeNode *root)
 {
  inorder(root);
  int minDiff = INT_MAX;
  for (int i = 1; i < nodes.size(); i++)
  {
   minDiff = min(minDiff, nodes[i] - nodes[i - 1]);
  }
  return minDiff;
 }
};