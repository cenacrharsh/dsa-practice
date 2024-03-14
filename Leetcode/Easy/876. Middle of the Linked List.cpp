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

// # Tutorial: PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU

//! Single Traversal

/*
> Time Complexity: O(N/2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *slow = head, *fast = head;
        // odd ele: fast-> next == NULL, even ele (2nd mid): fast == NULL, even ele (1st mid): fast -> next -> next == NULL;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

//! (N/2) + 1 node is always the middle node (in case of even we get 2nd middle)

/*
> Time Complexity: O(N) + O(N/2)
> Space Complexity: O(1)
*/