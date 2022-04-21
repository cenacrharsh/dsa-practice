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
 int minimumRounds(vector<int> &tasks)
 {
  map<int, int> cnt;
  for (int i : tasks)
   ++cnt[i];
  int ans = 0;
  for (auto i : cnt)
  {
   if (i.second == 1)
    return -1;
   ans += (i.second - 1) / 3 + 1;
  }
  return ans;
 }
};

//! Contest Sol

class Solution
{
public:
 int minimumRounds(vector<int> &tasks)
 {
  map<int, int> taskMap;
  for (int i = 0; i < tasks.size(); i++)
  {
   taskMap[tasks[i]]++;
  }
  int round = 0;
  while (taskMap.size() != 0)
  {
   for (auto i : taskMap)
   {
    if (i.second < 2)
    {
     return -1;
    }

    if (i.second % 3 == 0)
    {
     int temp = i.second / 3;
     taskMap[i.first] -= (temp * 3);
     round += temp;
    }
    else
    {
     taskMap[i.first] -= 2;
     round++;
    }

    if (taskMap[i.first] == 0)
    {
     auto it = taskMap.find(i.first);
     taskMap.erase(it);
    }
   }
  }

  return round;
 }
};