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

// # Tutorial: https://www.youtube.com/watch?v=L42U6E8Cu6Q

/*
> Time Complexity: O(N + N) => traverse then go back and delete
> Space Complexity: O(N)
*/

class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode *> mp;
        mp[0] = dummy;
        int prefixSum = 0;

        while (head != NULL)
        {
            prefixSum += head->val;

            //* check if current prefix sum already exists in map
            if (mp.find(prefixSum) != mp.end())
            {
                ListNode *start = mp[prefixSum];

                //* delete all nodes starting from start->next till head
                ListNode *temp = start->next;
                int prefixSumTemp = prefixSum + temp->val;
                while (temp != head)
                {
                    mp.erase(prefixSumTemp);
                    temp = temp->next;
                    prefixSumTemp += temp->val;
                }

                //* start should point to next node of curr node
                start->next = head->next;
            }
            else
            {
                mp[prefixSum] = head;
            }

            head = head->next;
        }

        return dummy->next;
    }
};