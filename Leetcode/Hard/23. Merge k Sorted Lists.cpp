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

//! Using Priority Queue

// # Tutorial: https://www.youtube.com/watch?v=1zktEppsdig&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=28

/*
> Time Complexity: O(K * Log(K)) + O(N * K * Log(K))
> Space Complexity: O(K)
*/

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq; //* value->node

        //* push heads of all given LL into min heap, TC: O(K) * O(Log(K)) where each operation on PQ takes Log(K) time where K is size of PQ
        for (auto head : lists)
        {
            if (head)
            {
                pq.push(make_pair(head->val, head));
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        //* TC: (K*N) * 3Log(K), K*N is total number of elements in PQ and 3 operations on PQ in each iteration
        while (!pq.empty())
        {
            //* pick smallest value from heap and add it to ans
            ListNode *smallestNode = pq.top().second;
            pq.pop();

            temp->next = smallestNode;
            temp = temp->next;

            //* push next node of smallest node into heap
            if (smallestNode->next)
            {
                pq.push(make_pair(smallestNode->next->val, smallestNode->next));
            }
        }
        return dummy->next;
    }
};
