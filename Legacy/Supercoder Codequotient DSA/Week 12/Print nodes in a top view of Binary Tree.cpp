#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=Et9OCDNvJ78

//! Level Order Traversal

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

struct Node
{
 int data;
 Node *left, *right;
};

void printTopView(Node *root)
{
 // Write your code here
 if (root == NULL)
 {
  return;
 }
 map<int, int> mp; // line -> top most value on that line
 queue<pair<Node *, int>> q;
 q.push({root, 0});
 while (!q.empty())
 {
  auto it = q.front();
  q.pop();

  Node *curr = it.first;
  int lineNum = it.second;

  if (mp.find(lineNum) == mp.end())
  {
   mp[lineNum] = curr->data;
  }

  if (curr->left != NULL)
  {
   q.push({curr->left, lineNum - 1});
  }

  if (curr->right != NULL)
  {
   q.push({curr->right, lineNum + 1});
  }
 }

 for (auto it : mp)
 {
  cout << it.second << " ";
 }
}
