#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
 int data;
 struct Node *left, *right;
};

struct Node *newNode(int data)
{
 struct Node *node = (struct Node *)malloc(sizeof(struct Node));
 node->data = data;
 node->left = node->right = NULL;
 return (node);
}

struct Node *insertLevelOrder(int arr[], struct Node *root, int i, int n)
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

struct Node *buildTree(int t[], int n)
{
 struct Node *root = (struct Node *)malloc(sizeof(struct Node));
 root = insertLevelOrder(t, root, 0, n);
 return (root);
}

#include <stack>
void printInorder(struct Node *root)
{
 if (root == NULL)
 {
  return;
 }
 stack<Node *> nodes;
 Node *curr = root;
 while (nodes.size() != 0 || curr != NULL)
 {
  while (curr != NULL)
  {
   nodes.push(curr);
   curr = curr->left;
  }
  curr = nodes.top();
  nodes.pop();
  cout << curr->data << " ";
  curr = curr->right;
 }
}

int main()
{
 int a[10], n, i;
 cin >> n;
 if (n > 0)
 {
  for (i = 0; i < n; i++)
   cin >> a[i];
  struct Node *root = NULL;
  root = buildTree(a, n);
  printInorder(root);
 }
 return 0;
}
