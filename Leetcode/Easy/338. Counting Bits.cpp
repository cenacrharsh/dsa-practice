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
 vector<int> countBits(int n)
 {
  vector<int> ans(n + 1, 0);
  int count = 0;
  for (int i = n; i >= 0; i--)
  {
   int num = i;
   while (num != 0)
   {
    num = num & (num - 1);
    count++;
   }
   ans[i] = count;
   count = 0;
  }
  return ans;
 }
};