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

int treeHeight(Node *t1)
{
 // Write your code here
 if (t1 == NULL)
 {
  return -1;
 }

 int leftSubtreeHeight = treeHeight(t1->left);
 int rightSubtreeHeight = treeHeight(t1->right);

 return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}
