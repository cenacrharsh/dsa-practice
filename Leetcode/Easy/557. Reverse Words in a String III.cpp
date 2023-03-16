#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using 2 pointers
class Solution
{
public:
 string reverseWords(string s)
 {
  int n = s.size();
  int start = 0, end = -1;
  for (int i = 0; i <= n; i++)
  {
   if ((s[i] == ' ') || (i == n))
   {
    end = i - 1;
    while (start < end)
    {
     swap(s[start], s[end]);
     start++;
     end--;
    }
    start = i + 1;
   }
  }
  return s;
 }
};

//* or

class Solution
{
public:
 string reverseWords(string s)
 {
  int lastSpaceIndex = -1;
  int len = (int)s.size();
  for (int strIndex = 0; strIndex <= len; strIndex++)
  {
   if (strIndex == len || s[strIndex] == ' ')
   {
    int startIndex = lastSpaceIndex + 1;
    int endIndex = strIndex - 1;
    while (startIndex < endIndex)
    {
     char temp = s[startIndex];
     s[startIndex] = s[endIndex];
     s[endIndex] = temp;
     startIndex++;
     endIndex--;
    }
    lastSpaceIndex = strIndex;
   }
  }
  return s;
 };
};

//! Using reverse function
class Solution
{
public:
 string reverseWords(string s)
 {
  int n = s.size();
  int start = 0;
  for (int end = 0; end <= n; end++)
  {
   if ((s[end] == ' ') || (end == n))
   {
    reverse(s.begin() + start, s.begin() + end);
    start = end + 1;
   }
  }
  return s;
 }
};

//! Create a new string
//* no space at end
class Solution
{
public:
 string reverseWords(string s)
 {
  string ans = "";
  string currWord = "";
  int n = s.size();
  for (int i = 0; i <= n; i++)
  {
   if ((s[i] == ' ') || (i == n))
   {
    ans += currWord;
    if (i != n)
    {
     ans += " ";
    }
    currWord = "";
   }
   else
   {
    currWord = s[i] + currWord;
   }
  }
  return ans;
 }
};
//* append " " at the end
class Solution
{
public:
 string reverseWords(string s)
 {
  string ans = "";
  string currWord = "";
  s = s + " ";
  for (int i = 0; i < s.size(); i++)
  {
   if (s[i] != ' ')
   {
    currWord = s[i] + currWord;
   }
   else
   {
    ans = ans + " " + currWord;
    currWord = "";
   }
  }
  return ans.substr(1);
 }
};