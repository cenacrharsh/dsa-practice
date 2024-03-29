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
 bool hasPathSum(TreeNode *root, int targetSum)
 {
  if (root == NULL)
  {
   // we crossed the leaf nodes but didn't find solution
   return false;
  }
  else if (root->left == NULL && root->right == NULL && targetSum - root->val == 0)
  {
   // we found our leaf node
   return true;
  }
  else
  {
   return hasPathSum(root->left, targetSum - root->val) ||
          hasPathSum(root->right, targetSum - root->val);
  }
 }
};