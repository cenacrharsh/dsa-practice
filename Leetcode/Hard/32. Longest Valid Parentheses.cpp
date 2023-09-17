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
 int longestValidParentheses(string s)
 {
  if (s.size() < 2)
  {
   return 0;
  }

  stack<int> st;

  for (int i = 0; i < s.size(); i++)
  {
   if (s[i] == '(')
   {
    st.push(i);
   }
   else
   {
    // current closing bracket
    if (!st.empty() && s[st.top()] == '(')
    {
     st.pop();
    }
    else
    {
     st.push(i);
    }
   }
  }

  int maxLen = 0;
  int endTerminal = s.size();

  while (!st.empty())
  {
   int startTerminal = st.top();
   st.pop();
   maxLen = max(maxLen, endTerminal - startTerminal - 1);
   endTerminal = startTerminal;
  }

  return max(maxLen, endTerminal);
 }
};