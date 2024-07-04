#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// # Tutorial: https://www.youtube.com/watch?v=SOY3c6yzzwk

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        int sum = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        ListNode *temp = head->next;
        while(temp != NULL) {
            if(temp->val == 0) {
                ListNode *newNode = new ListNode(sum);
                curr->next = newNode;
                curr = curr->next;
                sum = 0;
            }
            sum += temp->val;
            temp = temp->next;
        }
        return dummy->next;
    }
};

