#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=hXEEr5WekSQ

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

class Solution
{
public:
 string removeDuplicates(string s)
 {
  stack<char> st;
  for (int i = 0; i < s.size(); i++)
  {
   char current_char = s[i];
   if (!st.empty() && st.top() == current_char)
   {
    st.pop();
   }
   else
   {
    st.push(current_char);
   }
  }
  string ans = "";
  while (!st.empty())
  {
   ans = st.top() + ans;
   st.pop();
  }
  return ans;
 }
};