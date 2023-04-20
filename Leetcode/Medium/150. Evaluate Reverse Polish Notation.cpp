#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/")
            {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                if (tokens[i] == "+")
                {
                    st.push(op1 + op2);
                }
                else if (tokens[i] == "-")
                {
                    st.push(op1 - op2);
                }
                else if (tokens[i] == "*")
                {
                    st.push(op1 * op2);
                }
                else if (tokens[i] == "/")
                {
                    st.push(op1 / op2);
                }
            }
            else
            {
                int ele = stoi(tokens[i]);
                st.push(ele);
            }
        }
        return st.top();
    }
};