#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=tqQ5fTamIN4&list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c&index=1

//! Using 1 Queue

class MyStack
{
public:
    queue<int> q;

    MyStack()
    {
    }

    /* TC: O(N) */
    //* every time we push a new element we have to reverse the stack so that the current element is always at front of queue
    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    /* TC: O(1) */
    int pop()
    {
        int element = q.front();
        q.pop();
        return element;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.size() == 0;
    }
};

//! Using 2 Queues

class MyStack
{
public:
    queue<int> q1, q2;

    MyStack()
    {
    }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        int top_element = q1.front();
        q1.pop();
        return top_element;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};
