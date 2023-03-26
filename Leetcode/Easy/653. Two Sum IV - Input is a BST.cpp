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
 bool helper(TreeNode *root, int k, unordered_map<int, int> &m)
 {
  if (root == NULL)
  {
   return false;
  }

  int target = k - root->val;
  if (m.find(target) != m.end())
  {
   return true;
  }
  else
  {
   m[root->val]++;
  }

  return helper(root->left, k, m) || helper(root->right, k, m);
 }
 bool findTarget(TreeNode *root, int k)
 {
  unordered_map<int, int> m;
  return helper(root, k, m);
 }
};