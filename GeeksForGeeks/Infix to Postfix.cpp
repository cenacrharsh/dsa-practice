#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        unordered_map<char, int> priority;
        priority['^'] = 3;
        priority['/'] = 2;
        priority['*'] = 2;
        priority['+'] = 1;
        priority['-'] = 1;

        stack<char> st;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            {
                ans += s[i]; //* if character is an operand add it to the result
            }
            else if (s[i] == '(')
            {
                st.push(s[i]); //* push '(' into the stack
            }
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); //* pop the '(' from stack
            }
            else
            {
                //* whenever we push an operator into stack it's previous in stack should have lower priority than the current operator
                while (!st.empty() && (priority[s[i]] <= priority[st.top()]))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
