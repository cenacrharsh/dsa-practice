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
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

/*

    Time Complexity : O(L)
    Space Complexity : O(1)

    Where L is the number of nodes in the Linked-List.

*/

/*
Iterative Approach

> In this approach, we reverse one block at a time while traversing through the list. Let the block size be denoted by K. We need to follow the following steps to reverse the linked list as required :

* Reverse the subsequent K consecutive nodes or the remaining nodes in the list, whichever is smaller. In the meanwhile, keep track of the information of four nodes, the node before head, head, tail, and the node after tail.


* At last, put the reversed sub-list back to the correct position, in between the node before head (former head) and the node after the tail (former tail).

* Move forward to reverse the next sub-list.


Repeat the above steps till we reach the end of the linked list or we have considered the entire block array.
*/

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    // If linked list is empty, return head of the linked list.
    if (head == NULL)
    {
        return NULL;
    }

    // Variable to keep track of the current index in the block array.
    int idx = 0;

    Node *prev = NULL, *cur = head, *temp = NULL;
    Node *tail = NULL, *join = NULL;
    bool isHeadUpdated = false;

    // Reverse nodes until the list is empty or entire block array has been considered.
    while (cur != NULL && idx < n)
    {

        // K represents the size of the current block
        int K = b[idx];

        // Just move to the next block if size of the current block is zero
        if (K == 0)
        {
            idx++;
            continue;
        }

        join = cur;
        prev = NULL;

        // Reverse nodes until end of list is reached or current block has been reversed
        while (cur != NULL && K--)
        {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        // Update the head pointer when reversing the first block.
        if (isHeadUpdated == false)
        {
            head = prev;
            isHeadUpdated = true;
        }

        // Tail pointer keeps track of the last node before the current K-reversed linked list.
        // We join the tail pointer with the current K-reversed linked list's head.
        if (tail != NULL)
        {
            tail->next = prev;
        }

        // The tail is then updated to the last node of the current K-reversed linked list.
        tail = join;
        idx++;
    }

    // If entire block is iterated and reached at end, then we append the remaining nodes to the tail of the partial modified linked list.
    if (tail != NULL)
    {
        tail->next = cur;
    }

    // Return the head of the linked list.
    return head;
}