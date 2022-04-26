#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=fKgZiCXb6zs

struct TreeNode
{
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//! Iterative

class Solution
{
public:
 TreeNode *invertTree(TreeNode *root)
 {
  if (root == nullptr)
  {
   return root;
  }

  queue<TreeNode *> tree;
  tree.push(root);

  while (!tree.empty())
  {
   TreeNode *front = tree.front();
   tree.pop();

   if (front->left != nullptr)
   {
    tree.push(front->left);
   }

   if (front->right != nullptr)
   {
    tree.push(front->right);
   }

   // swap
   TreeNode *temp = front->left;
   front->left = front->right;
   front->right = temp;
  }

  return root;
 }
};

//! Recursive

class Solution
{
public:
 TreeNode *invertTree(TreeNode *root)
 {
  if (root == NULL)
  {
   return root;
  }

  TreeNode *left = invertTree(root->left);
  TreeNode *right = invertTree(root->right);

  // swap
  root->right = left;
  root->left = right;

  return root;
 }
};