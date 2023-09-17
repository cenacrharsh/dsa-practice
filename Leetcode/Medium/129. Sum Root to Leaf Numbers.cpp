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

//! Approach 1
class Solution
{
public:
 void helper(TreeNode *&root, int currNum, int &ans)
 {
  if (root == NULL)
   return;

  //* add the value of node to currNum
  currNum = currNum * 10 + root->val;

  //* check if it's a leaf node
  if (root->left == NULL && root->right == NULL)
  {
   ans = ans + currNum;
   return;
  }

  helper(root->left, currNum, ans);
  helper(root->right, currNum, ans);
 }
 int sumNumbers(TreeNode *root)
 {
  int ans = 0;
  helper(root, 0, ans);
  return ans;
 }
};

//! Approach 2
class Solution
{
public:
 int ans = 0;
 int helper(TreeNode *&root, int currNum)
 {
  // leaf node
  if (root != NULL && root->left == NULL && root->right == NULL)
  {
   currNum = currNum * 10 + root->val;
   return currNum;
  }

  int leftNum = 0, rightNum = 0;
  if (root->left != NULL)
  {
   leftNum = helper(root->left, currNum * 10 + root->val);
  }
  if (root->right != NULL)
  {
   rightNum = helper(root->right, currNum * 10 + root->val);
  }

  return leftNum + rightNum;
 }
 int sumNumbers(TreeNode *root)
 {
  return helper(root, 0);
 }
};