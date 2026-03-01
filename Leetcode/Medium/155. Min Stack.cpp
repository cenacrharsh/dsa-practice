#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=NdDIaH91P0g&list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c&index=4

//! Using Formula

/*
> Time Complexity: O(1)
> Space Complexity: O(N)
*/

class MinStack
{
public:
    //* whenever an element which can replace our currentMinimum appears we'll use a formula to insert the modified element inside the stack so as when its time pop that element from stack we'll be able to recover the previous minimum element from it's value
    //* 2 * originalValue - prevMinimum = newValue
    //* prevMinimum = 2 * originalValue - newValue
    stack<long long> st;
    long long currentMinimum;

    MinStack()
    {
    }

    void push(int val)
    {
        long long originalValue = (long long)val;
        if (st.empty())
        {
            st.push(originalValue);
            this->currentMinimum = originalValue;
        }
        else
        {
            if (originalValue > currentMinimum)
            {
                st.push(originalValue);
            }
            else
            {
                st.push(long(2 * originalValue * 1LL) - currentMinimum);
                this->currentMinimum = originalValue;
            }
        }
    }

    void pop()
    {
        long long topElement = st.top();
        st.pop();

        //* check if removed element was a modified value
        if (topElement < currentMinimum)
        {
            long long previousMinimum = (2 * currentMinimum) - topElement;
            currentMinimum = previousMinimum;
        }
    }

    int top()
    {
        //* cases where val becomes < currentMinimum
        //* we can say, val - prevMinimum < 0 => val + val - prevMinimum < val => newValue < val, so we see the newValue would always be lesser than the originalValue and hence for the cases where st.top() < currentMinimum we know it was a replaced value

        long long topElement = st.top();
        if (currentMinimum < topElement)
        {
            return topElement;
        }
        else
        {
            return currentMinimum;
        }
    }

    int getMin()
    {
        return this->currentMinimum;
    }
};

//! Stack Of Pairs

/*
> Time Complexity: O(1)
> Space Complexity: O(2N)
*/

class MinStack
{
public:
    stack<pair<int, int>> st;

    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            st.push({val, min(st.top().second, val)});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

//! Using 2 Stack

/*
> Efficient Solution:

* You need to make two separate stacks for solving the problem.

* The first stack would have the actual number and the second stack would contain the minimum number present in the current stack.

* There is a modification in this approach, that the second stack(for maintaining minimum elements) would only push an element if it is less than or equal to the element at its top. This would help us reduce the space complexity(although in the worst case it would remain the same).

* Now, when we need to push a number in the stack, we first need to check if the stack is empty or not. If the stack is empty, we simply push the integer in both the stacks. Otherwise, we push the integer in the first stack and take the minimum of the top of the second stack and the current number and push it in the second stack.

* For ‘POP’, we need to check if the stack is empty. If the stack is empty, we return ‘-1’. Otherwise, we first save the top of the first stack and pop it. Finally, we return it.

* For ‘TOP’, we need to check if the stack is empty. If the stack is empty, we return ‘-1’. Otherwise, we return the top of the first stack.

* For ‘GETMIN’, we need to check if the stack is empty. If the stack is empty, we return ‘-1’. Otherwise, we return the top of the second stack.

* For ‘ISEMPTY’, we just need to check if the stack is empty.
*/

/*
> Time Complexity: O(1) -> for all operations
> Space Complexity: O(1)
*/

class MinStack
{
public:
    stack<int> s1, s2;

    MinStack()
    {
    }

    void push(int val)
    {
        s1.push(val);
        if (s2.empty() || val <= s2.top())
        {
            s2.push(val);
        }
    }

    void pop()
    {
        if (s1.empty())
        {
            return;
        }
        if (s1.top() == s2.top())
        {
            s2.pop();
        }
        s1.pop();
    }

    int top()
    {
        if (s1.empty())
        {
            return -1;
        }
        return s1.top();
    }

    int getMin()
    {
        if (s1.empty())
        {
            return -1;
        }
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
