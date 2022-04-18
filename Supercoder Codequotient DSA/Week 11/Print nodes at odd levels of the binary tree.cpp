#include <bits/stdc++.h>
using namespace std;

struct Node
{
 int data;
 Node *left, *right;
};

Node *newNode(int data)
{
 Node *node = new Node();
 node->data = data;
 node->left = node->right = NULL;
 return (node);
}

Node *buildTree(int arr[], int n)
{
 if (n <= 0 || arr[0] == -1)
  return NULL;

 Node *root = newNode(arr[0]);
 queue<Node *> q;
 q.push(root);

 int i = 1;
 while (i < n && !q.empty())
 {
  Node *parent = q.front();
  q.pop();

  // If left child exists
  if (arr[i] != -1)
  {
   parent->left = newNode(arr[i]);
   q.push(parent->left);
  }
  i++;

  // If right child exists
  if (i < n && arr[i] != -1)
  {
   parent->right = newNode(arr[i]);
   q.push(parent->right);
  }
  i++;
 }
 return root;
}

void printOdd(Node *root)
{
 // Write your code here
 if (root == NULL)
 {
  return;
 }
 int level = 1;
 queue<Node *> nodes;
 nodes.push(root);
 while (nodes.size() != 0)
 {
  int nodeCount = nodes.size();
  while (nodeCount > 0)
  {
   Node *curr = nodes.front();
   if (level % 2 != 0)
   {
    cout << curr->data << " ";
   }
   nodes.pop();
   if (curr->left != NULL)
   {
    nodes.push(curr->left);
   }
   if (curr->right != NULL)
   {
    nodes.push(curr->right);
   }
   nodeCount--;
  }
  level++;
 }
}

int main()
{
 int n, i;
 cin >> n;
 int a[n];
 for (i = 0; i < n; i++)
  cin >> a[i];
 struct Node *root = NULL;
 if (n != 0)
  root = buildTree(a, n);
 printOdd(root);
 return 0;
}