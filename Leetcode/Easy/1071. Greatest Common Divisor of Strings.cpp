#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=ZzVTirSj4sE

class Solution
{
public:
 string gcdOfStrings(string str1, string str2)
 {
  // bigger string in str1, smaller in str2
  if (str2.size() > str1.size())
  {
   return gcdOfStrings(str2, str1);
  }

  // if smaller string is empty, return what is left of bigger string
  if (str2.empty())
  {
   return str1;
  }

  // if not empty, then check if smaller string exists as a substring in the bigger string or not, if not return ""
  if (str1.substr(0, str2.size()) != str2)
  {
   return "";
  }

  // now that we know smaller string exists as a substring in str1, check the portion of str1 that isleft after str2's part
  return gcdOfStrings(str1.substr(str2.size()), str2);
 }
};