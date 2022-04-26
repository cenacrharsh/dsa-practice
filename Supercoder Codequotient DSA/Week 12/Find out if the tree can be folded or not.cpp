#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct Node
{
 int data;
 Node *left, *right;
};

int isMirrorStructure(Node *leftNode, Node *rightNode)
{
 if (leftNode == NULL && rightNode == NULL)
 {
  return 1;
 }

 if (leftNode == NULL || rightNode == NULL)
 {
  return 0;
 }

 return (isMirrorStructure(leftNode->left, rightNode->right) && isMirrorStructure(leftNode->right, rightNode->left));
}
int isFoldable(Node *root)
{
 // Write your code here
 if (root == NULL)
 {
  return 1;
 }

 return isMirrorStructure(root->left, root->right);
}