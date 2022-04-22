#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! All Nodes should be within a range of values

struct Node
{
 int data;
 Node *left, *right;
};

int isBinarySearchTreeHelper(Node *root, int min, int max)
{
 if (root == NULL)
 {
  return 1;
 }

 if (root->data <= min || root->data >= max)
 {
  return false;
 }

 return (isBinarySearchTreeHelper(root->left, min, root->data) && isBinarySearchTreeHelper(root->right, root->data, max));
}

int isBinarySearchTree(Node *root)
{
 // Write your code here
 return isBinarySearchTreeHelper(root, INT_MIN, INT_MAX);
}

//! Inorder Traversal

int prev = INT_MIN;

int isBinarySearchTree(Node *root)
{
 // Write your code here
 if (root == NULL)
 {
  return 1;
 }

 if (!isBinarySearchTree(root->left))
 {
  return false;
 }

 if (root->data <= ::prev)
 {
  return false;
 }

 ::prev = root->data;

 return isBinarySearchTree(root->right);
}
