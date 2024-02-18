#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// # Tutorial: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        //* we want to reach the node just before the node to be deleted
        //* we'll move a pointer n stpes ahead then move both pointers together, when first pointer reaches last node second pointer reacher node just before one we have to delete
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (n--)
        {
            fast = fast->next;
        }
        //* N = Length of Linked List
        if (fast == NULL)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;
        return head;
    }
};

//! Old Solution

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        ListNode *first = head, *second = head, *prev = NULL;
        for (int i = 0; i < n; i++)
        {
            second = second->next;
        }

        while (second != NULL)
        {
            prev = first;
            first = first->next;
            second = second->next;
        }

        if (prev == NULL)
        {
            head = first->next;
        }
        else
        {
            prev->next = first->next;
        }

        return head;
    }
};