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

// # Tutorial: https://www.youtube.com/watch?v=D2vI2DNJGd8&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=10

//! Iterative

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *prevNode = NULL, *currNode = head, *nextNode = NULL;
        while (currNode != NULL)
        {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        head = prevNode;
        return head;
    }
};

//! Recursive

/*
> Time Complexity: O(N)
> Space Complexity: O(N) => Recursive Stack Space
*/

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *newHead = reverseList(head->next);
        ListNode *frontNode = head->next; //* front node of LL sent for reversal or last node of LL after reversal
        frontNode->next = head;
        head->next = NULL;
        return newHead;
    }
};
