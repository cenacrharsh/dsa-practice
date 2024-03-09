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

// # Tutorial: https://www.youtube.com/watch?v=lRY_G-u_8jk&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=11

/*
> Time Complexity: O(N/2) + O(N/2) + O(N/2) + O(N/2) ~ O(2N) => 2 reversals, 1 finding mid, 1 comparison
> Space Complexity: O(1)
*/

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head, *next = head;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        //* divide the LL into 2 parts, then reverse the second half, then compare one by one the nodes of both halves
        //* if odd LL stop at middle node (fast->next == NULL), if even then stop at first middle (fast->next->next == NULL)

        //* 0 or 1 elements means always Pallindrome
        if (head == NULL || head->next == NULL)
        {
            return true;
        }

        //* find middle of LL
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //* reverse second half of LL
        ListNode *newHead = reverse(slow->next);

        //* compare 2 halves
        ListNode *temp1 = head, *temp2 = newHead;
        while (temp2 != NULL)
        {
            if (temp1->val != temp2->val)
            {
                reverse(newHead);
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        //* restore original LL
        reverse(newHead);

        return true;
    }
};