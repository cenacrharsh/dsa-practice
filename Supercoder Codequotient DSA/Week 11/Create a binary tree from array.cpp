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

Node *insertLevelOrder(int arr[], Node *root, int i, int n)
{
 // Base case for recursion
 if (i < n)
 {
  Node *temp = newNode(arr[i]);
  root = temp;
  // insert left child
  root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
  // insert right child
  root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
 }
 return root;
}
Node *buildTree(int arr[], int n)
{
 // Write your code here
 if (n == 0)
 {
  return NULL;
 }
 Node *root = new Node;
 return insertLevelOrder(arr, root, 0, n);
}

int main()
{
 int n, i;
 cin >> n;
 int a[n];
 for (i = 0; i < n; i++)
  cin >> a[i];
 struct Node *root = NULL;
 root = buildTree(a, n);
 inOrder(root);
}