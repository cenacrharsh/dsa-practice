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
 void traverse(TreeNode *root, int k, priority_queue<int> &pq)
 {
  if (root == NULL)
  {
   return;
  }
  pq.push(root->val);
  if (pq.size() > k)
  {
   pq.pop();
  }
  traverse(root->left, k, pq);
  traverse(root->right, k, pq);
 }

 int kthSmallest(TreeNode *root, int k)
 {
  priority_queue<int> pq;
  traverse(root, k, pq);
  return pq.top();
 }
};