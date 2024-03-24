#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct ListNode
{
    ListNode *next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        //* find the middle node, in case of even we need first middle node
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //* reverse the 2nd half of LL
        ListNode *secondHalfHead = slow->next;
        slow->next = NULL;
        secondHalfHead = reverseList(secondHalfHead);

        //* traverse in both halves and merge them
        ListNode *firstHalfHead = head;
        while (secondHalfHead != NULL)
        {
            ListNode *temp1 = firstHalfHead->next, *temp2 = secondHalfHead->next;

            firstHalfHead->next = secondHalfHead;
            secondHalfHead->next = temp1;

            firstHalfHead = temp1;
            secondHalfHead = temp2;
        }
    }
};