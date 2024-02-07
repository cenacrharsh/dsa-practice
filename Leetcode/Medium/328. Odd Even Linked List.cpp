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

// # Tutorial: https://www.youtube.com/watch?v=qf6qp7GzD5Q&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=7

/*
> Time Complexity: O(N/2) * 2 (2 steps inside while loop) => O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *odd = head, *even = head->next, *evenHead = head->next;

        //* since even always lies ahead of odd we can just check for even in while loop
        while (even != NULL && even->next != NULL)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead; //* connect end of odd list to evenHead
        return head;
    }
};

//! Maintaining Count

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *oddHead = head,
                 *evenHead = head->next,
                 *temp = head->next->next,
                 *odd = oddHead,
                 *even = evenHead;
        int count = 2;
        while (temp != NULL)
        {
            count++;
            if (count % 2 != 0)
            {
                odd->next = temp;
                odd = temp;
            }
            else
            {
                even->next = temp;
                even = temp;
            }
            temp = temp->next;
        }
        odd->next = evenHead;
        even->next = NULL;
        return oddHead;
    }
};