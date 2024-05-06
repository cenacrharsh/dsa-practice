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

//# Tutorial: https://www.youtube.com/watch?v=lIar1skcQYI&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=22

/*
> Time Complexity: O(N) + O(N) -> Reversal + Finding Kth Node
> Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* findKthNode(ListNode* node, int k) {
        k = k - 1;
        while(node != NULL && k > 0) {
            k--;
            node = node->next;
        }
        return node;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head, *nextNode = NULL, *prevLastNode = NULL;
        while(temp != NULL) {
            ListNode *kthNode = findKthNode(temp, k);
            if(kthNode == NULL) {
                //* if LL doesn't even have one group to reverse, in that case our prevNode will be NULL and we don't have to do anything
                if(prevLastNode != NULL) {
                    prevLastNode->next = temp;
                }
                break;
            }

            //* we can't reverse a portion of a LL so we break off this part and reverse it
            nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp); //* we already know the head of reversed LL will be the kthNode

            //* if it's the first group then we have to make sure we update the head of the LL as well
            if(temp == head) {
                head = kthNode;
            } else {
                prevLastNode->next = kthNode;
            }

            //* maintain the previous last node to reconnect the broken links in LL
            prevLastNode = temp;
            temp = nextNode;
        }
        return head;
    }
};

