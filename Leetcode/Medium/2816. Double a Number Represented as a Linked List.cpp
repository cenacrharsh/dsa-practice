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

//! Using Pointers

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        //* since we only have to double the number, we now N->[0, 9] so the maximum number we can get after doubling N is [0, 18] and max carry we can generate is 1
        ListNode *curr = head, *prev = NULL;
        while (curr != NULL)
        {
            int newValue = curr->val * 2;
            if (newValue < 10)
            {
                curr->val = newValue;
            }
            else
            {
                curr->val = newValue % 10;
                //* prev == NULL indicates curr is at head
                if (prev == NULL)
                {
                    ListNode *newNode = new ListNode(1);
                    newNode->next = head;
                    head = newNode;
                }
                else
                {
                    prev->val += 1;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};

//! Using Stack

/*
> Time Complexity: O(N) + O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        int carry = 0;
        stack<ListNode *> st;

        ListNode *temp = head;
        while (temp != NULL)
        {
            st.push(temp);
            temp = temp->next;
        }

        while (!st.empty())
        {
            ListNode *currNode = st.top();
            st.pop();
            int num = currNode->val * 2 + carry;
            currNode->val = num % 10;
            carry = num / 10;
        }

        if (carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};