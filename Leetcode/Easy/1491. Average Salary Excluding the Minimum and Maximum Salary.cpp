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
 double average(vector<int> &salary)
 {
  int totalSalary = 0, minSalary = INT_MAX, maxSalary = INT_MIN;
  for (auto it : salary)
  {
   totalSalary += it;
   minSalary = min(minSalary, it);
   maxSalary = max(maxSalary, it);
  }
  return (double)(totalSalary - minSalary - maxSalary) / (double)(salary.size() - 2);
 }
};