#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Contest Solution

class Solution
{
public:
 int divisorSubstrings(int num, int k)
 {
  string numStr = to_string(num);
  int n = numStr.size();
  int count = 0;
  for (int i = 0; i <= n - k; i++)
  {
   string temp = "";
   temp = numStr.substr(i, k);
   int tempNum = stoi(temp);
   if (tempNum != 0 && num % tempNum == 0)
   {
    count++;
   }
  }
  return count;
 }
};