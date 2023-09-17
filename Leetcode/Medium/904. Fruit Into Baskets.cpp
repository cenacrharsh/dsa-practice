#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Solution 1

class Solution
{
public:
 int totalFruit(vector<int> &fruits)
 {
  int count = 0;
  int maxCount = INT_MIN;
  int l = 0, r = 0;
  unordered_map<int, int> check;
  while (r < fruits.size())
  {
   if (check.find(fruits[r]) != check.end())
   {
    count++;
    maxCount = max(maxCount, count);
    check[fruits[r]]++;
    r++;
   }
   else
   {
    if (check.size() < 2)
    {
     count++;
     maxCount = max(maxCount, count);
     check[fruits[r]]++;
     r++;
    }
    else
    {
     if (check[fruits[l]] == 1)
     {
      check.erase(fruits[l]);
     }
     else
     {
      check[fruits[l]]--;
     }
     l++;
     count--;
    }
   }
  }
  return maxCount;
 }
};

//! Solution 2

class Solution
{
public:
 int totalFruit(vector<int> &fruits)
 {
  int count = 0;
  int maxCount = INT_MIN;
  int l = 0, r = 0;
  unordered_map<int, int> check;
  while (r < fruits.size())
  {
   check[fruits[r]]++;
   while (check.size() > 2)
   {
    check[fruits[l]]--;
    if (check[fruits[l]] == 0)
    {
     check.erase(fruits[l]);
    }
    l++;
    count--;
   }
   count++;
   maxCount = max(maxCount, count);
   r++;
  }
  return maxCount;
 }
};