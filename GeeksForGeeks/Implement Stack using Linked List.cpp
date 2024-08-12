#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;

    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyStack
{
private:
    StackNode *top;

public:
    void push(int x)
    {
        StackNode *newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == NULL)
        {
            return -1;
        }
        StackNode *toBeDeletedNode = top;
        int element = top->data;
        top = top->next;
        delete toBeDeletedNode;
        return element;
    }

    MyStack() { top = NULL; }
};
