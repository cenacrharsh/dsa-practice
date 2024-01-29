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

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        //* we won't be able to delete node if it's the last node in the list
        if (node != NULL && node->next != NULL)
        {
            ListNode *nextNode = node->next;
            node->val = nextNode->val;
            node->next = nextNode->next;
        }
    }
};