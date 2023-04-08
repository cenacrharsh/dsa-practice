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

// # Tutorial: https://www.youtube.com/watch?v=rPbzUW7usJE

//! Bit Manipulation

/*
by left shifting by 1, we always have a 0 as the last bit. So OR’ing with 1 is same as adding 1. Basically

0 | 1 == 0+1 == 1
0 | 0 == 0+0 == 0
*/

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        //* assume that the first is the last node so we do * 2^0, but as soon as we find another node, we know we should inc the power of all prev numbers by 1, so we multiply the current running sum by 2 and then add the new digit * 2^0
        int ans = 0;
        ListNode* temp = head;
        while(temp) {
            ans = (ans << 1) | temp->val; //* same thing as multiplying previous value of ans by 2 and then adding the current digit to it
            temp = temp->next;
        }
        return ans;
    }
};

//! Arithmetic

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        //* assume that the first digit is the last digit so we do * 2^0, but as soon as we find another node, we know we should inc the power of all prev numbers by 1, so we multiply the current running sum by 2 and then add the new digit * 2^0
        int ans = 0;
        ListNode *temp = head;
        while (temp)
        {
            ans *= 2;
            ans += temp->val; // temp->val * pow(2, 0)
            temp = temp->next;
        }
        return ans;
    }
};

//! 2 iterations

/*
> Time Complexity: O(2N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int count = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        int k = count - 1;
        int ans = 0;
        temp = head;
        while (temp != NULL)
        {
            ans += (temp->val * pow(2, k));
            k--;
            temp = temp->next;
        }
        return ans;
    }
};

//! Using Vector

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        vector<int> nums;
        ListNode *temp = head;
        while (temp != NULL)
        {
            nums.insert(nums.begin(), temp->val);
            temp = temp->next;
        }
        int k = 0;
        int ans = 0;
        for (auto num : nums)
        {
            ans += (num * pow(2, k));
            k++;
        }
        return ans;
    }
};