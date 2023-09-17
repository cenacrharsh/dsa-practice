#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=_-QHfMDde90

/*
> Time Complexity: O(n)
> Space Complexity: O(n) => auxiliary stack space
*/

struct TreeNode
{
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
 TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
 {
  if (root == NULL || root == p || root == q)
  {
   return root;
  }

  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);

  if (left == NULL)
  {
   return right;
  }
  else if (right == NULL)
  {
   return left;
  }
  else
  {
   // both left and right are not null, we found our result
   return root;
  }
 }
};