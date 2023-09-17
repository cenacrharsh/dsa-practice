#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=hFwakLj7wFA, https://www.youtube.com/watch?v=bTA3OLAeTi4

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
 TreeNode *trimBST(TreeNode *root, int low, int high)
 {
  if (root == NULL)
  {
   return NULL;
  }

  //* if root is in range
  if (root->val >= low && root->val <= high)
  {
   root->left = trimBST(root->left, low, high);
   root->right = trimBST(root->right, low, high);
   return root;
  }

  //* if root is more than high, so we need lesser values to be in range
  if (root->val > high)
  {
   return trimBST(root->left, low, high);
  }

  //* if root is less than low, so we need higher values to be in range
  if (root->val < low)
  {
   return trimBST(root->right, low, high);
  }

  return root;
 }
};