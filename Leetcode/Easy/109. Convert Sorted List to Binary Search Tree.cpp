#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct ListNode
{
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//! Use slow & fast pointer, and construct complete BST using Recursion
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
 TreeNode *convertToBST(ListNode *low, ListNode *high)
 {
  if (low == high)
   return NULL;

  // find middle of linked list
  ListNode *slow = low;
  ListNode *fast = low;
  while (fast != high && fast->next != high)
  {
   slow = slow->next;
   fast = fast->next->next;
  }

  TreeNode *root = new TreeNode(slow->val);
  root->left = convertToBST(low, slow);
  root->right = convertToBST(slow->next, high);
  return root;
 }
 TreeNode *sortedListToBST(ListNode *head)
 {
  if (head == NULL)
   return NULL;
  return convertToBST(head, NULL);
 }
};

//! Use vector and construct BST (not complete BST)
class Solution
{
public:
 TreeNode *helper(int i, int j, vector<int> v)
 {
  if (i > j)
  {
   return NULL;
  }
  int mid = i + (j - i) / 2;
  TreeNode *root = new TreeNode(v[mid]);
  root->left = helper(i, mid - 1, v);
  root->right = helper(mid + 1, j, v);
  return root;
 }
 TreeNode *sortedListToBST(ListNode *head)
 {
  vector<int> v;
  ListNode *temp = head;
  while (temp != NULL)
  {
   v.push_back(temp->val);
   temp = temp->next;
  }
  return helper(0, v.size() - 1, v);
 }
};