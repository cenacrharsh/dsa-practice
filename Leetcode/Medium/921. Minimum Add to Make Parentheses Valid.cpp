#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
  int minAddToMakeValid(string s)
  {
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
      {
        st.push('(');
      }
      else if (s[i] == ')')
      {
        if (!st.empty() && st.top() == '(')
        {
          st.pop();
        }
        else
        {
          st.push(')');
        }
      }
    }
    return st.size();
  }
};