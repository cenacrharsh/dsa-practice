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
    string preToInfix(string pre_exp)
    {
        stack<string> st;
        int i = pre_exp.size() - 1;
        while (i >= 0)
        {
            if ((pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') || (pre_exp[i] >= 'a' && pre_exp[i] <= 'z') || (pre_exp[i] >= '0' && pre_exp[i] <= '9'))
            {
                st.push(string(1, pre_exp[i]));
            }
            else
            {
                string operand1 = st.top();
                st.pop();
                string operand2 = st.top();
                st.pop();

                st.push("(" + operand1 + pre_exp[i] + operand2 + ")");
            }
            i--;
        }
        return st.top();
    }
};
