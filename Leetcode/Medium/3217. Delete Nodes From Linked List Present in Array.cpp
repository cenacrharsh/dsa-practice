#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
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

class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_map<int, int> mp;
        for (int num : nums)
        {
            mp[num] = 1;
        }
        ListNode *dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode *temp = dummyNode;
        while (temp->next != NULL)
        {
            if (mp.find(temp->next->val) != mp.end())
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return dummyNode->next;
    }
};