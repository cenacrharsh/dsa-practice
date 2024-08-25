#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=xwjS0iZhw4I&list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c&index=2

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }

                char topElement = st.top();
                st.pop();

                if (s[i] == ')' && topElement == '(' ||
                    s[i] == '}' && topElement == '{' ||
                    s[i] == ']' && topElement == '[')
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty(); //* if still some opening brackets are left it'll return false
    }
};

// OR

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == '}')
            {
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == ']')
            {
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (!st.empty())
        {
            return false;
        }

        return true;
    }
};