#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// # Tutorial: https://www.youtube.com/watch?v=q570bKdrnlw&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=29

//! No Extra Space

/*
> Time Complexity: O(N) + O(N) + O(N) -> 3 traversals
> Space Complexity: O(N) -> required for ans LL
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        //* create new nodes and insert in between the original nodes
        //* populate the random pointers
        //* populate the next pointers and separate the old and new LL
        Node *temp = head;
        while (temp != NULL)
        {
            Node *copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = temp->next->next;
        }
        temp = head;
        while (temp != NULL)
        {
            if (temp->random != NULL)
            {
                temp->next->random = temp->random->next;
            }
            else
            {
                temp->next->random = NULL;
            }
            temp = temp->next->next;
        }
        Node *dummy = new Node(-1);
        Node *curr = dummy;
        temp = head;
        while (temp != NULL)
        {
            curr->next = temp->next;
            curr = curr->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};

//! Unordered Map

/*
> Time Complexity: O(N) + O(N) -> 2 traversal
> Space Complexity: O(N) + O(N) -> Map + Deep Copy LL (ans)
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        //* create a deep copy of nodes and store the old and new nodes in a hashmap for future reference
        unordered_map<Node *, Node *> mp; //* old node->new node
        Node *temp = head;
        while (temp != NULL)
        {
            Node *newNode = new Node(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            //* the copiedNode next and random pointers should point to copied version of original nodes
            Node *copiedNode = mp[temp];
            copiedNode->next = mp[temp->next];
            copiedNode->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};