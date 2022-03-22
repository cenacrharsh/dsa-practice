#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

bool areBracketsBalanced(char exp[])
{
 // Write your code here
 stack<char> st;
 int i = 0;
 while (exp[i] != '\0')
 {
  if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
  {
   st.push(exp[i]);
  }
  else if (exp[i] == ')')
  {
   if (!st.empty() && st.top() == '(')
   {
    st.pop();
   }
   else
   {
    return false;
   }
  }
  else if (exp[i] == '}')
  {
   if (!st.empty() && st.top() == '{')
   {
    st.pop();
   }
   else
   {
    return false;
   }
  }
  else if (exp[i] == ']')
  {
   if (!st.empty() && st.top() == '[')
   {
    st.pop();
   }
   else
   {
    return false;
   }
  }
  i++;
 }

 if (!st.empty())
 {
  return false;
 }

 return true;
}
