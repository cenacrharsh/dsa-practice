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
    ListNode(int x) : val(x), next(NULL) {}
};

// # Tutorial: https://www.youtube.com/watch?v=wiOo4DC5GGA&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=16

//! Floyd’s Cycle-Finding Algorithm | Tortoise & The Hare Algorithm

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        //* Proof: once both pointers enter cycle, fast is ahead of slow by say distance D, now when they start moving fast moves towards slow by 2 nodes while slow moves away by 1 node so effectively distances b/w them decreases by 1 node everytime, and since D % 1 == 0 i.e. if distance decreaes by 1 every time it's bound to reach 0 at some point, not applicable say if we move fast by 3x as not all D % 2 != 0 for all values of D
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *slow = head, *fast = head;

        //* for LL with no cycle i.e. linear LL, fast pointer would reach last node in case of odd LL and it would reach NULL in case of even LL so they become our stop conditions, in case of cycle there is no stop condition, we stop when we both pointers reach the same node
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};