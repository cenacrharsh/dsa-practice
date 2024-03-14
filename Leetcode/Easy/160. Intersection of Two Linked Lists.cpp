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

// # Tutorial: https://www.youtube.com/watch?v=0DYoPz2Tpt4&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=13

//! Single Traversal

/*
> Time Complexity: O(N1 + N2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        //* if the very first node is the intersection node we need the code to not enter the while loop as it is our answer
        while (temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;

            //* covers both cases of finding the intersection or no intersection exists as in case no intersection both pointers reach NULL simultaneously and hence we end up returning NULL which was required
            if (temp1 == temp2)
            {
                return temp1;
            }

            //* moving to opposite heads makes sure we make for the gap in b/w the pointers and that they align themselves after being swapped
            if (temp1 == NULL)
            {
                temp1 = headB;
            }
            if (temp2 == NULL)
            {
                temp2 = headA;
            }
        }
        return temp1;
    }
};

//! Calculate Length of 2 LL

/*
> Time Complexity: O(N1) + O(N2) + O(N2 - N1) + O(N2) ~ O(N1 + 2N2) => N1 is smaller than N2
> Space Complexity: O(1)
*/

class Solution
{
public:
    ListNode *getIntersection(int d, ListNode *headA, ListNode *headB)
    {
        ListNode *temp1 = headA, *temp2 = headB;
        for (int i = 0; i < d; i++)
        {
            temp1 = temp1->next;
        }
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1 == temp2)
            {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
    int getCount(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int c1 = getCount(headA);
        int c2 = getCount(headB);
        if (c1 > c2)
        {
            int d = c1 - c2;
            return getIntersection(d, headA, headB);
        }
        else
        {
            int d = c2 - c1;
            return getIntersection(d, headB, headA);
        }
    }
};