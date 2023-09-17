#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Explanation - https://www.youtube.com/watch?v=QM0klnvTQzk
class Solution
{
public:
 int subarraysDivByK(vector<int> &nums, int k)
 {
  unordered_map<int, int> remainder;
  remainder[0] = 1;
  int count = 0;
  int rem = 0;
  long long int sum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
   sum += nums[i];

   rem = sum % k;
   if (rem < 0)
   {
    rem += k; // Kn - y = Kn - y + K - K = K(n-1) + (K-y) = Kn' - y + K, eg. 7n - 4 = 7n' + 3
   }

   if (remainder.find(rem) != remainder.end())
   {
    count += remainder[rem];
    remainder[rem]++;
   }
   else
   {
    remainder[rem] = 1;
   }
  }
  return count;
 }
};