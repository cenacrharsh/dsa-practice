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

// # Tutorial: https://www.youtube.com/watch?v=2Kd0KKmmHFc&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=18

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //* step 1: detect loop
        //* step 2: find starting point
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};