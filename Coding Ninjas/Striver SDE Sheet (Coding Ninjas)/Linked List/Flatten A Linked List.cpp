#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=ykelywHJWLg&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=26

/*
> Time Complexity: O(N) + O(2M) -> N vertical nodes, M depth of child nodes -> recursion + merging
> Space Complexity: O(N) -> recursive stack space
*/

Node *merge(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else
        {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = nullptr;
    }

    if (list1)
    {
        res->child = list1;
    }
    else
    {
        res->child = list2;
    }

    if (dummyNode->child)
    {
        dummyNode->child->next = nullptr;
    }
    res->child->next = nullptr;
    return dummyNode->child;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mergedHead = flattenLinkedList(head->next);

    head = merge(head, mergedHead);

    return head;
}
