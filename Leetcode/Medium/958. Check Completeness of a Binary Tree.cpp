#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

//! BFS

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
 bool isCompleteTree(TreeNode *root)
 {
  // as soon as we hit a node which has either left or right missing, we know that should be the last level
  if (root == NULL)
  {
   return true;
  }
  queue<TreeNode *> q;
  q.push(root);
  bool lastLevel = false;
  while (!q.empty())
  {
   TreeNode *curr = q.front();
   q.pop();

   if (curr->left != NULL)
   {
    if (lastLevel)
    {
     return false;
    }
    q.push(curr->left);
   }
   else
   {
    lastLevel = true;
   }

   if (curr->right != NULL)
   {
    if (lastLevel)
    {
     return false;
    }
    q.push(curr->right);
   }
   else
   {
    lastLevel = true;
   }
  }
  return true;
 }
};