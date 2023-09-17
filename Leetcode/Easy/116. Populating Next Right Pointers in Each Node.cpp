#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=3MRPQFUpoA0

// # Solution Post: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/solutions/1654181/c-python-java-simple-solution-w-images-explanation-bfs-dfs-o-1-optimized-bfs/

class Node
{
public:
 int val;
 Node *left;
 Node *right;
 Node *next;

 Node() : val(0), left(NULL), right(NULL), next(NULL) {}

 Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

 Node(int _val, Node *_left, Node *_right, Node *_next)
     : val(_val), left(_left), right(_right), next(_next) {}
};

//! Using BFS + DFS

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
 Node *connect(Node *root)
 {
  Node *head = root;
  while (head != NULL && head->left != NULL)
  {
   // start from the first node in the level
   Node *currNode = head;
   while (true)
   {
    // update next pointers of children if they exist
    currNode->left->next = currNode->right;

    // if we hit the rightmost node in the level, we don't need to update it's right child as it's next is already NULL
    if (currNode->next == NULL)
    {
     break;
    }

    currNode->right->next = currNode->next->left;

    // traversing a level form left->right
    currNode = currNode->next;
   }
   // changing the level
   head = head->left;
  }
  return root;
 }
};

//! BFS (Right -> Left Traversal)

/*
> Time Complexity: O(N)
> Space Complexity: O(N) => space required to make queue
*/

class Solution
{
public:
 Node *connect(Node *root)
 {
  if (root == NULL)
  {
   return NULL;
  }

  queue<Node *> nodesLeft;
  nodesLeft.push(root);

  while (!nodesLeft.empty())
  {
   int nodesInCurrLevel = nodesLeft.size();
   Node *rightNode = nullptr; // keeping initial value of rightNode as NULL
   while (nodesInCurrLevel--)
   {
    Node *currNode = nodesLeft.front();
    nodesLeft.pop();

    currNode->next = rightNode;
    rightNode = currNode; // update rightNode as currNode for next iteration

    // we always insert right child first to ensure right->left traversal
    // if one chile exists the other one does too, since perfect BT
    if (currNode->left != NULL)
    {
     nodesLeft.push(currNode->right);
     nodesLeft.push(currNode->left);
    }
   }
  }
  return root;
 }
};

//! Using DFS

/*
> Time Complexity: O(N)
> Space Complexity: O(log N) => required for recursive stack. The maximum depth of recursion is equal to the height of tree which in this case of perfect binary tree is equal to O(logN)
*/

class Solution
{
public:
 Node *connect(Node *root)
 {
  if (root == NULL)
  {
   return NULL;
  }

  if (root->left != NULL)
  {
   // next of root's left is assigned as root's right
   root->left->next = root->right;

   // if we have a node to the right of curr node we update it's right child else we leave it as NULL
   if (root->next != NULL)
   {
    // next of root's right is assigned as root's next's left (if root's next exist)
    root->right->next = root->next->left;
   }

   // recurse left and right
   connect(root->left);
   connect(root->right);
  }
  return root;
 }
};