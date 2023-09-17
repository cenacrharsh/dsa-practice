#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

//! 2 pointers
class Solution
{
public:
 int compress(vector<char> &chars)
 {
  int n = chars.size();
  int i = 0, j = 0;
  while (j < n)
  {
   int count = 1;
   while (j < n - 1 && chars[j] == chars[j + 1])
   {
    j++;
    count++;
   }
   chars[i++] = chars[j++];

   // convert count to string if > 1 and insert it digit by digit into the chars vector
   if (count > 1)
   {
    string countStr = to_string(count);
    for (auto s : countStr)
    {
     chars[i++] = s;
    }
   }
  }
  return i;
 }
};