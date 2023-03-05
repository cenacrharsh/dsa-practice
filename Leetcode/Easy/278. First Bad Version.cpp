#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
 int firstBadVersion(int n)
 {
  int l = 1, r = n;
  while (l <= r)
  {
   int mid = l + (r - l) / 2;
   if (isBadVersion(mid))
   {
    if (isBadVersion(mid - 1))
    {
     r = mid - 1;
    }
    else
    {
     return mid;
    }
   }
   else
   {
    l = mid + 1;
   }
  }
  return -1;
 }
};