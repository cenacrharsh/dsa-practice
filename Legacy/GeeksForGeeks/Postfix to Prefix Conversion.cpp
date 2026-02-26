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
    string postToPre(string post_exp)
    {
        stack<string> st;
        int i = 0;
        while (i < post_exp.size())
        {
            if ((post_exp[i] >= 'A' && post_exp[i] <= 'Z') || (post_exp[i] >= 'a' && post_exp[i] <= 'z') || (post_exp[i] >= '0' && post_exp[i] <= '9'))
            {
                st.push(string(1, post_exp[i]));
            }
            else
            {
                string operand2 = st.top();
                st.pop();
                string operand1 = st.top();
                st.pop();

                st.push(post_exp[i] + operand1 + operand2);
            }
            i++;
        }
        return st.top();
    }
};