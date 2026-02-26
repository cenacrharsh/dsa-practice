#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N) + O(N) => loop + concat strings
> Space Complexity: O(N)
*/

class Solution
{
public:
    //* when we encounter an operator pick the last 2 elements from stack and insert the operator b/w them and wrap them in bracket and put it back into the stack
    string postToInfix(string exp)
    {
        stack<string> st;
        int i = 0;
        while (i < exp.size())
        {
            if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))
            {
                st.push(string(1, exp[i]));
            }
            else
            {
                string operand2 = st.top();
                st.pop();
                string operand1 = st.top();
                st.pop();

                // Use += instead of multiple + operators
                st.push("(" + operand1 + exp[i] + operand2 + ")");
            }
            i++;
        }
        return st.top();
    }
};