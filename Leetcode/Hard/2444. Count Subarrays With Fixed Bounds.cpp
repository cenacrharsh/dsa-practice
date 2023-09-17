#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=zLv5H6CaTgE

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 long long countSubarrays(vector<int> &nums, int minK, int maxK)
 {
  long long ans = 0;
  int start = 0, minIndex = 0, maxIndex = 0;
  bool minFound = false, maxFound = false;
  for (int i = 0; i < nums.size(); i++)
  {
   int num = nums[i];

   if (num < minK || num > maxK)
   {
    minFound = false;
    maxFound = false;
    start = i + 1;
   }

   if (num == minK)
   {
    minFound = true;
    minIndex = i;
   }

   if (num == maxK)
   {
    maxFound = true;
    maxIndex = i;
   }

   if (minFound && maxFound)
   {
    // cout << "start :" << start << " minIndex: " << minIndex << " maxIndex: " << maxIndex << " range: " << (min(minIndex, maxIndex) - start + 1) << endl;

    //* the number of elements b/w start and min(minIndex, maxIndex) is the number of options/subarrays we have that would be valid eg. [2,3,7,2,3,4,5,2,1] => [2,3,4,5,2,1] here [5,2,1] is a must so options to start subarray are between 2 to first occ of 5 i.e [2,3,4,5]
    ans += (min(minIndex, maxIndex) - start + 1);
   }
  }
  return ans;
 }
};