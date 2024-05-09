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

// # Tutorial: https://www.youtube.com/watch?v=8ocB7a_c-Cc&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=27

/*
> Time Complexity: O(Log(N)) * (N + N/2)
> Space Complexity: O(Log(N)) -> recursive stack space
*/

//! Merge Sort

class Solution
{
public:
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val < head2->val)
            {
                temp->next = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }

        if (head1 != NULL)
        {
            temp->next = head1;
        }
        else
        {
            //* no need to check condition here, as even if we have same length LL, the last node would be left in either LL at which point the loop would terminate
            temp->next = head2;
        }

        return dummy->next;
    }

    ListNode *findMiddle(ListNode *head)
    {
        //* in case of even length we have to return first middle as if [1,2,3,4] then if middle node is 2 then we can separate the 2 halves as [1,2] and [3,4]
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //! O(Log(N)) -> Max recursive depth is log(N)
    ListNode *mergeSort(ListNode *head)
    {
        //* if head is null or only one node is left
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        //* find middle node and make sure it points to null to separate 2 halves of LL
        ListNode *middleNode = findMiddle(head); //! O(N/2)
        ListNode *leftHead = head;
        ListNode *rightHead = middleNode->next;
        middleNode->next = NULL;

        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);

        //* merge 2 sorted halves of LL and return updated head of LL
        return merge(leftHead, rightHead); //! O(N)
    }

    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }
};