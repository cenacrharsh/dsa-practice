#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using DFS

/*
> Time Complexity: O(N), N is the min no. of nodes in either Tree
> Space Complexity: O(N)
*/

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
 TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
 {
  // if either of root1 or root2 is NULL, we return the other one
  if (root1 == NULL)
  {
   return root2;
  }

  if (root2 == NULL)
  {
   return root1;
  }

  // we'll select either of root1 or root2 and use it as our new node
  root1->val += root2->val;
  root1->left = mergeTrees(root1->left, root2->left);
  root1->right = mergeTrees(root1->right, root2->right);
  return root1;
 }
};