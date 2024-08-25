#include <bits/stdc++.h>
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
