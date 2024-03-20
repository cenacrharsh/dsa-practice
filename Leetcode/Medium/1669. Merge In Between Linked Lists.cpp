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

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        int count = 0;
        ListNode *temp = list1;
        ListNode *start, *end;
        while (temp != NULL)
        {
            if (count == a - 1)
            {
                start = temp;
            }
            if (count == b + 1)
            {
                end = temp;
            }
            temp = temp->next;
            count++;
        }
        start->next = list2;
        ListNode *list2End;
        while (list2->next != NULL)
        {
            list2 = list2->next;
        }
        list2->next = end;
        return list1;
    }
};