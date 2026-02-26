#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Inorder Traversal

struct Node
{
 int data;
 Node *left, *right;
};

int findRightSibling(Node *root, int key)
{
 // Write your code here
 if (root == NULL)
 {
  return -1;
 }
 int ans = -1;
 queue<Node *> level;
 level.push(root);
 while (!level.empty())
 {
  int nodeCount = level.size();
  while (nodeCount--)
  {
   Node *curr = level.front();
   level.pop();

   if (curr->data == key)
   {
    if (nodeCount != 0)
    {
     Node *next = level.front();
     ans = next->data;
    }
    else
    {
     return -1;
    }
   }

   if (curr->left != NULL)
   {
    level.push(curr->left);
   }

   if (curr->right != NULL)
   {
    level.push(curr->right);
   }
  }
 }
 return ans;
}
