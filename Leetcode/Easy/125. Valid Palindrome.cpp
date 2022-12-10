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
 bool isPalindrome(string s)
 {
  string str = "";
  for (int i = 0; i < s.size(); i++)
  {
   if (isupper(s[i]) || isdigit(s[i]))
   {
    str += tolower(s[i]);
   }
   else if (islower(s[i]))
   {
    str += s[i];
   }
  }
  string reducedString = str;
  int left = 0;
  int right = str.size() - 1;
  while (left < right)
  {
   swap(str[left++], str[right--]);
  }
  if (reducedString == str)
  {
   return true;
  }
  return false;
 }
};