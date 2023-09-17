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
 double calculateTax(vector<vector<int>> &brackets, int income)
 {
  double tax = 0.0;
  double money = brackets[0][0];
  double percent = brackets[0][1];
  if (income >= money)
  {
   tax += (percent / 100) * money;
   income -= money;
  }
  else
  {
   tax += (percent / 100) * income;
   income = 0;
  }
  for (int i = 1; i < brackets.size(); i++)
  {
   money = brackets[i][0] - brackets[i - 1][0];
   percent = brackets[i][1];
   if (income >= money)
   {
    tax += (percent / 100) * money;
    income -= money;
   }
   else
   {
    tax += (percent / 100) * income;
    income = 0;
   }
  }
  return tax;
 }
};