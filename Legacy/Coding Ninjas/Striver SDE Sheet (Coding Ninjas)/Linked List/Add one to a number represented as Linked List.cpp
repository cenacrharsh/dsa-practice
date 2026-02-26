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
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// # Tutorial: https://www.youtube.com/watch?v=aXQWhbvT3w0&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=12

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

int helper(Node *node)
{
    if (node == NULL)
    {
        return 1; //* acts as +1 we have to do
    }

    int carry = helper(node->next);
    node->data = node->data + carry;

    if (node->data < 10)
    {
        return 0;
    }

    node->data = 0;
    return 1;
}

Node *addOne(Node *head)
{
    int carry = helper(head);

    if (carry == 1)
    {
        Node *newHead = new Node(carry);
        newHead->next = head;
        return newHead;
    }
    return head;
}
