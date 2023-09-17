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
 TreeNode *convertToBST(int i, int j, vector<int> &nums)
 {
  if (i > j)
   return NULL;
  int mid = i + (j - i) / 2;
  TreeNode *head = new TreeNode(nums[mid]);
  head->left = convertToBST(i, mid - 1, nums);
  head->right = convertToBST(mid + 1, j, nums);
  return head;
 }
 TreeNode *sortedArrayToBST(vector<int> &nums)
 {
  return convertToBST(0, nums.size() - 1, nums);
 }
};