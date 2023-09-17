#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Reverse second half of the LL

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        // find middle of LL (second middle)
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half of the LL
        ListNode *prev = NULL;
        ListNode *curr = slow;
        ListNode *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // calc twin sum's
        ListNode *firstHalf = head;
        ListNode *secondHalf = prev; // head of reversed LL
        int maxSum = INT_MIN;
        while (secondHalf != NULL)
        {
            int currSum = firstHalf->val + secondHalf->val;
            maxSum = max(maxSum, currSum);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return maxSum;
    }
};