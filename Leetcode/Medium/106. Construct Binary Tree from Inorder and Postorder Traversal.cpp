#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=7Z6ivS-TA3k

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
 TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
 {
  if (inorder.size() == 0 || postorder.size() == 0)
  {
   return NULL;
  }

  TreeNode *root = new TreeNode(postorder.back());

  if (postorder.size() == 1)
  {
   return root;
  }

  auto root_index = find(begin(inorder), end(inorder), postorder.back()) - inorder.begin();

  // [9,(3),15,20,7]
  vector<int> left_inorder(inorder.begin(), inorder.begin() + root_index);
  vector<int> right_inorder(inorder.begin() + root_index + 1, inorder.end());

  // [9,15,7,20,(3)]
  vector<int> left_postorder(postorder.begin(), postorder.begin() + root_index);    // if root index is at index i eg. 1, then we know left contains first i digits i.e 1 element in this case
  vector<int> right_postorder(postorder.begin() + root_index, postorder.end() - 1); // and the rest elements minus the last element which is the root goes to the right

  root->left = buildTree(left_inorder, left_postorder);
  root->right = buildTree(right_inorder, right_postorder);

  return root;
 }
};