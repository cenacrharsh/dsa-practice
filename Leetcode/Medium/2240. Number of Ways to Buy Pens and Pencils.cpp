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
 long long waysToBuyPensPencils(int total, int cost1, int cost2)
 {
  long long res = 0;
  for (int i = 0; i * cost1 <= total; ++i)
  {
   res += (total - i * cost1) / cost2 + 1;
  }
  return res;
 }
};

//! Contest Sol

class Solution
{
public:
 long long waysToBuyPensPencils(int total, int cost1, int cost2)
 {
  int nPen = 0;
  long long ans = 0;
  while (nPen * cost1 <= total)
  {
   int amtLeft = total - (nPen * cost1);
   int nPencil = amtLeft / cost2;
   ans = ans + (nPencil + 1);
   nPen++;
  }

  return ans;
 }
};
