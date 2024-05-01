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

// # Tutorial: https://www.youtube.com/watch?v=ePpV-_pfOeI&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=17

//! Using Previous Pointer
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        //* either maintain prev variable or reach the node before the middle node
        if(head == NULL || head->next == NULL) {
            return NULL; //* in case of one node it will be the middle and after deletion nothing is left so return NULL
        }
        ListNode *slow = head, *fast = head, *prev = NULL;
        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return head;
    }
};

//! Without Using Previous Variable
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        //* either maintain prev variable or reach the node before the middle node
        if(head == NULL || head->next == NULL) {
            return NULL; //* in case of one node it will be the middle and after deletion nothing is left so return NULL
        }
        ListNode *slow = head, *fast = head;
        fast = fast->next->next; //* by skipping one step we reach one node before the middle node
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};