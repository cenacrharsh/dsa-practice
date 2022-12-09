#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=qGBGSp8EAs8

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
 int res = 0;
 int maxAncestorDiff(TreeNode *root)
 {
  int mx = INT_MIN, mn = INT_MAX;
  helper(root, mx, mn);
  return res;
 }
 void helper(TreeNode *node, int mx, int mn)
 {
  if (!node)
   return;
  if (mx != INT_MIN)
   res = max(res, abs(mx - node->val));
  if (mn != INT_MAX)
   res = max(res, abs(node->val - mn));
  mx = max(mx, node->val);
  mn = min(mn, node->val);
  helper(node->left, mx, mn);
  helper(node->right, mx, mn);
 }
};