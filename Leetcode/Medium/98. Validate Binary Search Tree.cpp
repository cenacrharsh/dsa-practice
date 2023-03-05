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

//! All Parent Nodes Lie In A Range
class Solution
{
public:
 bool helper(TreeNode *root, long minValue, long maxValue)
 {
  if (root == NULL)
   return true;

  if (root->val <= minValue || root->val >= maxValue)
   return false;

  return (helper(root->left, minValue, root->val) &&
          helper(root->right, root->val, maxValue));
 }

 bool isValidBST(TreeNode *root)
 {
  return helper(root, LONG_MIN, LONG_MAX);
 }
};

//* or
class Solution
{
public:
 static bool isValidBSTHelper(TreeNode *root, long min, long max)
 {
  if (root == NULL)
  {
   return true;
  }

  if (root->val <= min || root->val >= max)
  {
   return false;
  }

  return (isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max));
 }

 bool isValidBST(TreeNode *root)
 {
  return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
 }
};

//! Inorder Traversal

class Solution
{
 long prev = LONG_MIN;

public:
 bool isValidBST(TreeNode *root)
 {
  if (root == NULL)
  {
   return true;
  }

  if (!isValidBST(root->left))
  {
   return false;
  }

  if (root->val <= prev)
  {
   return false;
  }

  prev = root->val;

  return isValidBST(root->right);
 }
};