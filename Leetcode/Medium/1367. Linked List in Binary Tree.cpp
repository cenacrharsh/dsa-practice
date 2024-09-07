#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
private:
    //* we'll check with each and every node of BT and if it matches the head of LL we'll consider it as a possible subpath and proceed to check all of it's children

    bool helper(ListNode *linkedListNode, TreeNode *binaryTreeNode)
    {
        if (linkedListNode == NULL)
        {
            return true;
        }

        if (binaryTreeNode == NULL)
        {
            return false;
        };

        if (linkedListNode->val == binaryTreeNode->val)
        {
            return helper(linkedListNode->next, binaryTreeNode->left) || helper(linkedListNode->next, binaryTreeNode->right);
        }

        return false;
    }

public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        //* since we keep going left and right we'll eventually hit null pointer execption so we need a check here
        if (root == NULL)
        {
            return false;
        }

        //* if instead of calling isSubPath() on the roots children we call helper() on the children then we'll limit ourselves to comparing only the root and it's childrens values to the LL head but by using isSubPath() we make sure that we not compare LL head with the root children but thier children and so on
        return helper(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};