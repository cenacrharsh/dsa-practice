#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=RJpy4A7LJrs

//! Using Stack (while keeping count of char as well)

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

class Solution
{
public:
 string removeDuplicates(string s, int k)
 {
  stack<vector<int>> st;
  for (int i = 0; i < s.size(); i++)
  {
   char current_char = s[i];

   if (!st.empty() && st.top()[0] == current_char)
   {
    st.top()[1]++;
   }
   else
   {
    vector<int> temp(2);
    temp[0] = current_char; //* char & int are interchangeable
    temp[1] = 1;            //* count of char
    st.push(temp);
   }

   if (st.top()[1] == k)
   {
    st.pop();
   }
  }

  string ans = "";
  while (!st.empty())
  {
   char ch = st.top()[0];
   int count = st.top()[1];
   while (count--)
   {
    ans += ch; //* ans = ch + ans; gives memory exceeded error
   }
   st.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
 }
};

//! Using Recursion (Gived Memory Exceeded Error)

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

class Solution
{
public:
 string removeDuplicates(string s, int k)
 {
  int count = 1;
  for (int i = 1; i < s.size(); i++)
  {
   if (s[i] == s[i - 1])
   {
    count++;
   }
   else
   {
    count = 1;
   }

   if (count == k)
   {
    string reduced = s.substr(0, i - k + 1) + s.substr(i + 1);
    return removeDuplicates(reduced, k);
   }
  }
  //* if no reduced string then return original string
  return s;
 }
};
