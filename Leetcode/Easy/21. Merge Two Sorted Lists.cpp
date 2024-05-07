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

//! 2 Pointers + Exchanging Links

// # Tutorial: https://www.youtube.com/watch?v=jXu-H7XuClE&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=24

/*
> Time Complexity: O(N1 + N2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *currNode = dummy;
        ListNode *temp1 = list1, *temp2 = list2;

        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val < temp2->val)
            {
                currNode->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                currNode->next = temp2;
                temp2 = temp2->next;
            }
            currNode = currNode->next;
        }

        if (temp1 != NULL)
        {
            currNode->next = temp1;
        }
        else if (temp2 != NULL)
        {
            currNode->next = temp2;
        }
        return dummy->next;
    }
};
