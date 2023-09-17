#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// #Tutorial: https://www.youtube.com/watch?v=2OBDP3Omi30

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
 string solve(TreeNode *root, unordered_map<string, int> &m, vector<TreeNode *> &ans)
 {
  if (root == NULL)
  {
   return "";
  }
  string str = to_string(root->val) + "," + solve(root->left, m, ans) + "," + solve(root->right, m, ans);
  m[str]++;
  if (m[str] == 2)
  {
   ans.push_back(root);
  }
  return str;
 }
 vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
 {
  unordered_map<string, int> m;
  vector<TreeNode *> ans;
  solve(root, m, ans);
  return ans;
 }
};