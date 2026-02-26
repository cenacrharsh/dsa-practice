#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
};

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    Node *last = NULL;
    while (curr != NULL)
    {
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;

        curr = curr->prev; //* as links have been reversed;
    }
    return last->prev;
}