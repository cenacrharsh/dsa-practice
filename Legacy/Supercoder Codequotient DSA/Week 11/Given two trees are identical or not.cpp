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

//# Tutorial: https://www.youtube.com/watch?v=BhuvF_-PWS0
int areSameTree(Node *t1, Node *t2)
{
 // Write your code here
 if (t1 == NULL || t2 == NULL)
 {
  return t1 == t2;
 }
 // Using Preorder Traversal
 return ((t1->data == t2->data) && (areSameTree(t1->left, t2->left)) && (areSameTree(t1->right, t2->right)));
}

int main()
{
 int n, m, i;
 cin >> n;
 int a[n];
 for (i = 0; i < n; i++)
  cin >> a[i];
 cin >> m;
 int b[m];
 for (i = 0; i < m; i++)
  cin >> b[i];
 struct Node *root = NULL;
 root = buildTree(a, n);
 struct Node *root2 = NULL;
 root2 = buildTree(b, m);
 cout << areSameTree(root, root2);
 return 0;
}