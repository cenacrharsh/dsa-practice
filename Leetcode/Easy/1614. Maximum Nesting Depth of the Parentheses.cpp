#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Without Stack

//> Max consecutive opening brackets

class Solution
{
public:
  int maxDepth(string s)
  {
    int maxDepth = 0;
    int depth = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
      {
        depth++;
      }
      else if (s[i] == ')')
      {
        depth--;
      }
      maxDepth = max(maxDepth, depth);
    }
    return maxDepth;
  }
};

//! With Stack

class Solution
{
public:
  int maxDepth(string s)
  {
    stack<char> st;
    int maxDepth = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
      {
        st.push(s[i]);
        maxDepth = max(maxDepth, static_cast<int>(st.size()));
      }
      else if (s[i] == ')')
      {
        if (!st.empty())
        {
          st.pop();
        }
      }
    }
    return maxDepth;
  }
};