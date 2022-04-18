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

struct Node *newNode(int data)
{
 struct Node *node = new Node();
 node->data = data;
 node->left = node->right = NULL;
 return (node);
}

void inOrder(struct Node *root)
{
 if (root != NULL)
 {
  inOrder(root->left);
  printf("%d ", root->data);
  inOrder(root->right);
 }
}

void inorder(Node *root)
{
 // Write your code here
 if (root == NULL)
 {
  return;
 }
 inorder(root->left);
 cout << root->data << " ";
 inorder(root->right);
}
void preorder(Node *root)
{
 // Write your code here
 if (root == NULL)
 {
  return;
 }
 cout << root->data << " ";
 preorder(root->left);
 preorder(root->right);
}
void postorder(Node *root)
{
 // Write your code here
 if (root == NULL)
 {
  return;
 }
 postorder(root->left);
 postorder(root->right);
 cout << root->data << " ";
}

int main()
{
 int a[10], n, i;
 cin >> n;
 if (n > 0)
 {
  for (i = 0; i < n; i++)
   cin >> a[i];
  Node *root = NULL;
  root = buildTree(a, n);
  inorder(root);
  cout << endl;
  preorder(root);
  cout << endl;
  postorder(root);
  cout << endl;
 }
 return 0;
}
