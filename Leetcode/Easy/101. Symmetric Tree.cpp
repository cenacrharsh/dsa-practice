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

//! Iterative

//> 1 queue
class Solution
{
public:
 bool isSymmetric(TreeNode *root)
 {
  if (root == NULL)
  {
   return true;
  }

  queue<TreeNode *> q;

  q.push(root->left);
  q.push(root->right);

  while (!q.empty())
  {
   TreeNode *left = q.front();
   q.pop();

   TreeNode *right = q.front();
   q.pop();

   if (left == NULL && right == NULL)
   {
    continue;
   }

   if (left == NULL || right == NULL)
   {
    return false;
   }

   if (left->val != right->val)
   {
    return false;
   }

   q.push(left->left);
   q.push(right->right);

   q.push(left->right);
   q.push(right->left);
  }
  return true;
 }
};

//> 2 queues
class Solution
{
public:
 bool isSymmetric(TreeNode *root)
 {
  if (root == NULL)
  {
   return true;
  }

  queue<TreeNode *> q1;
  queue<TreeNode *> q2;

  q1.push(root->left);
  q2.push(root->right);

  while (!q1.empty() && !q2.empty())
  {
   TreeNode *left = q1.front();
   q1.pop();

   TreeNode *right = q2.front();
   q2.pop();

   if (left == NULL && right == NULL)
   {
    continue;
   }

   if (left == NULL || right == NULL)
   {
    return false;
   }

   if (left->val != right->val)
   {
    return false;
   }

   q1.push(left->left);
   q1.push(left->right);

   q2.push(right->right);
   q2.push(right->left);
  }
  return true;
 }
};

//! Recursive

class Solution
{
public:
 bool isMirror(TreeNode *node1, TreeNode *node2)
 {
  if (node1 == NULL && node2 == NULL)
  {
   return true;
  }

  if (node1 == NULL || node2 == NULL)
  {
   return false;
  }

  if (node1->val != node2->val)
  {
   return false;
  }

  return (isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left));
 }

 bool isSymmetric(TreeNode *root)
 {
  if (root == NULL)
  {
   return true;
  }

  return isMirror(root->left, root->right);
 }
};