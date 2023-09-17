#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N^3)
> Space Complexity: O(1)
*/

class Solution
{
public:
 int countTriples(int n)
 {
  int count = 0;
  for (int i = 1; i <= n; i++)
  {
   for (int j = 1; j <= n; j++)
   {
    for (int k = 1; k <= n; k++)
    {
     if (i * i + j * j == k * k)
     {
      count++;
     }
    }
   }
  }
  return count;
 }
};