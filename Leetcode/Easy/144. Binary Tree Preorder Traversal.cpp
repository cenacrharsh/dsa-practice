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

//! Using Stack (Iterative Solution)

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

class Solution
{
public:
 vector<int> preorderTraversal(TreeNode *root)
 {
  vector<int> ans;
  if (root == NULL)
   return ans;

  stack<TreeNode *> nodesLeft;
  nodesLeft.push(root);

  while (!nodesLeft.empty())
  {
   TreeNode *currNode = nodesLeft.top();
   nodesLeft.pop();

   // root
   ans.push_back(currNode->val);

   // right
   if (currNode->right != NULL)
   {
    nodesLeft.push(currNode->right);
   }

   // left, pushed after right so that it can come before left while popping
   if (currNode->left != NULL)
   {
    nodesLeft.push(currNode->left);
   }
  }
  return ans;
 }
};

//! Using Recursion

/*
> Time Complexity: O(n)
> Space Complexity: O(n) => auxiliary stack space
*/

class Solution
{
public:
 /*
 In a preorder traversal, we need to visit the root node first, then all left child nodes, followed by the right child nodes.
 */
 void helper(TreeNode *root, vector<int> &ans)
 {
  if (root == NULL)
  {
   return;
  }

  // root node
  ans.push_back(root->val);

  // left node
  helper(root->left, ans);

  // right node
  helper(root->right, ans);
 }
 vector<int> preorderTraversal(TreeNode *root)
 {
  vector<int> ans;
  helper(root, ans);
  return ans;
 }
};