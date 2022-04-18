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

void printAllPathsHelper(Node *root, string path, int &counter)
{
 if (root == NULL)
 {
  return;
 }
 if (root->left == NULL && root->right == NULL)
 {
  path = path + to_string(root->data) + " ";
  int pathLen = 0;
  for (int i = 0; i < path.size(); i++)
  {
   if (path[i] == ' ')
   {
    pathLen++;
   }
  }
  cout << path;
  cout << (pathLen - 1) << endl;
  path = "";
  counter++;
  return;
 }
 else
 {
  printAllPathsHelper(root->left, path + to_string(root->data) + " ", counter);
  printAllPathsHelper(root->right, path + to_string(root->data) + " ", counter);
 }
}

void printAllPaths(Node *root)
{
 // Write your code here
 if (root == NULL)
 {
  return;
 }
 int counter = 0;
 printAllPathsHelper(root, "", counter);
 cout << counter << endl;
}

int main()
{
 int n, i;
 cin >> n;
 int a[n];
 for (i = 0; i < n; i++)
  cin >> a[i];
 Node *root = NULL;
 if (n != 0)
  root = buildTree(a, n);
 printAllPaths(root);
 return 0;
}