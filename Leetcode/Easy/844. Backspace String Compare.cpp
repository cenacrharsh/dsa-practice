#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Stack

class Solution
{
public:
 bool backspaceCompare(string s, string t)
 {
  stack<char> st1, st2;

  for (char c : s)
  {
   if (c == '#')
   {
    if (!st1.empty())
    {
     st1.pop();
    }
   }
   else
   {
    st1.push(c);
   }
  }

  for (char c : t)
  {
   if (c == '#')
   {
    if (!st2.empty())
    {
     st2.pop();
    }
   }
   else
   {
    st2.push(c);
   }
  }

  if (st1.size() != st2.size())
  {
   return false;
  }

  while (st1.size() != 0)
  {
   int a = st1.top();
   int b = st2.top();
   st1.pop();
   st2.pop();

   if (a != b)
   {
    return false;
   }
  }

  return true;
 }
};