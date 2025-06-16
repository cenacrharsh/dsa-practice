#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Without Stack

class Solution
{
public:
  string removeOuterParentheses(string s)
  {
    string ans = "";
    int openBrackets = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
      {
        //* to avoid adding first ( to ans, we check first then inc count
        if (openBrackets > 0)
        {
          ans += s[i];
        }
        openBrackets++;
      }
      else
      {
        openBrackets--;
        //* to avoid adding lasat ) to ans, we dec first then add to ans
        if (openBrackets > 0)
        {
          ans += s[i];
        }
      }
    }
    return ans;
  }
};

//! Using Stack

class Solution
{
public:
  string removeOuterParentheses(string s)
  {
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
      {
        //* avoid first opening paranthesis, therefore we check first then push
        if (!st.empty())
        {
          ans += s[i];
        }
        st.push('(');
      }
      else
      {
        st.pop();
        //* avoid last closing paranthesis, therefore we pop first then consider adding
        if (!st.empty())
        {
          ans += s[i];
        }
      }
    }
    return ans;
  }
};