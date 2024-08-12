#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=tqQ5fTamIN4&list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c&index=1

//! Expensive Pop Operation - Better TC

/*
We have one input stack, onto which we push the incoming elements, and one output stack, from which we peek/pop. We move elements from input stack to output stack when needed, i.e., when we need to peek/pop but the output stack is empty. When that happens, we move all elements from input to output stack, thereby reversing the order so it's the correct order for peek/pop.

The loop in peek does the moving from input to output stack. Each element only ever gets moved like that once, though, and only after we already spent time pushing it, so the overall amortized cost for each operation is O(1).
*/

/*
> Time Complexity: O(1) (amortized)
> Space Complexity: O()
*/

class MyQueue
{
public:
    stack<int> s1, s2;

    //* we'll maintain 2 stacks, we'll push into s1 as usual but for pop and front operations we'll move all elements from s1 to s2 which will reverse the order of elements thereby making the element that was inserted first in s1 as our top element in s2 thus behaving like a queue, also until this s2 is empty we'll continue doing pop and front operations on it and meanwhile if we need to push we'll push into s1 as usual, until s2 is empty we don't need to push elements from s1 to s2 as order is already maintained in elememnts present in s2

    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    /* TC: O(N), SC: O(2 * Dynamic Space) */
    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int element = s2.top();
        s2.pop();
        return element;
    }

    /* TC: O(N), SC: O(2 * Dynamic Space) */
    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty()
    {
        return (s1.empty() && s2.empty());
    }
};

//! Expensive Push Operation

class MyQueue
{
public:
    stack<int> s1, s2;

    MyQueue()
    {
    }

    /* TC : O(2N), SC: O(2 * Dynamic Space) */
    //* we'll maintain 2 stacks, everytime before we push current elementn we'll move all existing elements into s2, then we'll insert new element into s1 then move all element back from s2 to s1, in this way the order in which elements are being inserted is maintained and the first elements to be pushed inside the queue are always at the front
    void push(int x)
    {
        //* Step 1
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }

        //* Step 2
        s1.push(x);

        //* Step 3
        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int element = s1.top();
        s1.pop();
        return element;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.size() == 0;
    }
};
