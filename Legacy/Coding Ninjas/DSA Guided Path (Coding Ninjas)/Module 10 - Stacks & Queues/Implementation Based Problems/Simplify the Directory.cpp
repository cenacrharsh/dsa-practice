#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#include <stack>
string simplifyDirectory(string path)
{
 // Write your code here
 stack<string> st;

 for (int i = 0; i < path.size(); i++)
 {
  if (path[i] == '/') //* ignore all extra /
  {
   continue;
  }

  string temp;
  while (i < path.size() && path[i] != '/')
  {
   temp += path[i]; //* make a string of all char in b/w two /
   i++;
  }

  if (temp == ".") //* . indicates stay in the current directory
  {
   continue;
  }
  else if (temp == "..")
  {
   if (!st.empty())
   {
    st.pop(); //* .. indicates move up one directory
   }
  }
  else
  {
   st.push(temp); //* anything else is a dir name, so push it
  }
 }

 //* adding all stack elements to ans
 string ans;
 while (!st.empty())
 {
  ans = "/" + st.top() + ans;
  st.pop();
 }

 //* if no directory or file is present
 if (ans.size() == 0)
  return "/";

 return ans;
}