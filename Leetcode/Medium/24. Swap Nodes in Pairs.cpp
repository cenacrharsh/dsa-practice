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

// # Tutorial: https://www.youtube.com/watch?v=OY09-51I-K0

//! Iterative

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        ListNode *curr = head;
        dummy->next = head;

        //* we need 2 elements to swap, so any time we have 0 or 1 elements left the loop terminates
        while (curr != NULL && curr->next != NULL)
        {
            //* -1 (prev) -> 1 (curr) -> 2 -> 3
            prev->next = curr->next;       //* -1 -> 2
            curr->next = curr->next->next; //* 1 -> 3
            prev->next->next = curr;       //* 2 -> 1

            //* -1 (prev) -> 2 -> 1 (curr) -> 3
            prev = curr; //* or prev = prev->next->next
            curr = curr->next;
        }

        return dummy->next;
    }
};

//> or
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }

        ListNode *temp = new ListNode();
        temp->next = head;
        ListNode *current = temp;

        /*
        ! 1 -> 2 -> 3 -> 4 =>
        ! 2 -> 1 -> 3 -> 4 =>
        ! 2 -> 1 -> 4 -> 3
        */

        while (current->next != NULL && current->next->next != NULL)
        {
            ListNode *first = current->next;
            ListNode *second = current->next->next;

            first->next = second->next;  //* 1 -> 3, 3 -> NULL
            current->next = second;      //* head -> 2, 1 -> 4
            current->next->next = first; //* 2 -> 1, 4 -> 3

            current = current->next->next; //* head -> 1
        }
        return temp->next;
    }
};

//! Recursive

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *temp = head->next;

        head->next = swapPairs(head->next->next); // recursion will give us the head of the next pair of elements after swapping
        temp->next = head;

        return temp;
    }
};