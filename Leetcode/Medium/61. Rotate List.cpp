#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct ListNode
{
	ListNode *next;
	int val;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//! Optimized Approach

/*
> Time Complexity: O(N) + O(N) -> find tail + find kth node
> Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* findKthNode(ListNode* node, int k) {
        int count = 1;
        while(node != NULL && k > 0) {
            if(count == k) {
                return node;
            }
            count++;
            node = node->next;
        }
        return node;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        //* find length of LL and last node, make last node point to head
        //* find (N-K)th node and make it point to NULL, also the next node to (N-K)th node becomes the new head of the LL

        if(head == NULL || k == 0) {
            return head;
        }

        //* find last node and count
        ListNode *tail = head;
        int count = 1;
        while(tail->next != NULL) {
            count++;
            tail = tail->next;
        }

        //* reduce k to be in range of length of LL if k > count, also if k = multiple of count we don't have to do anything
        k = k % count;
        if(k == 0) {
            return head;
        }
        tail->next = head;
        
        //* find (N-K)th node
        ListNode *newLastNode = findKthNode(head, count - k);
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};

//! Brute Force - K rotations

/*
> Time Complexity: O(k * n)
> Space Complexity: O(1)
*/

class Solution
{
    public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k < 1)
        {
            return head;
        }

        for (int i = 0; i < k; i++)
        {
            ListNode *lastNode = head;
            ListNode *secondLastNode = NULL;
            while (lastNode->next != NULL)
            {
                secondLastNode = lastNode;
                lastNode = lastNode->next;
            }
            lastNode->next = head;
            secondLastNode->next = NULL;
            head = lastNode;
        }
        return head;
    }
};