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

void findMirror(Node *root)
{
 // Write your code here
 if (root == NULL)
 {
  return;
 }

 findMirror(root->left);
 findMirror(root->right);

 // swap
 Node *temp = root->right;
 root->right = root->left;
 root->left = temp;
}