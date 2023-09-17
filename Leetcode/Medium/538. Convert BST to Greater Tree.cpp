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

/*
 Inorder Traversal of BST will give an ascending sequence of all values.
By slightly modifying the inorder traverse such that we firstly travel right subtree and then left subtree, we can get the descending order of the BST.
That is, before encoutering the current node, we have exactly visited all the values that greater than it. So we just need to set a variable(cur_sum) to keep track the summation of the visited nodes.
*/

class Solution
{
public:
 int sum = 0;

 TreeNode *convertBST(TreeNode *root)
 {
  if (root == NULL)
  {
   return NULL;
  }

  if (root->right)
  {
   convertBST(root->right);
  }

  root->val = root->val + sum;

  sum = root->val; //* root->val now consists sum of all nodes > it

  if (root->left)
  {
   convertBST(root->left);
  }

  return root;
 }
};