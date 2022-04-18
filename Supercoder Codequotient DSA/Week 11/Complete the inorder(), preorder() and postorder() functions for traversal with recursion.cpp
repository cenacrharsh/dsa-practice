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

Node *insertLevelOrder(int arr[], Node *root, int i, int n)
{
 if (i < n)
 {
  struct Node *temp = newNode(arr[i]);
  root = temp;

  root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

  root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
 }
 return root;
}

Node *buildTree(int t[], int n)
{
 Node *root = newNode(t[0]);
 root = insertLevelOrder(t, root, 0, n);
 return (root);
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
