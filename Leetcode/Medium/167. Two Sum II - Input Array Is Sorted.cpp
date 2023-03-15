#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(n * log(n))
> Space Complexity: O(1)
*/

//! Using Binary Search
class Solution
{
public:
 int findNumber(vector<int> &numbers, int num1, int low, int high)
 {
  while (low <= high)
  {
   int mid = low + (high - low) / 2;
   if (num1 == numbers[mid])
   {
    return mid;
   }
   else if (num1 < numbers[mid])
   {
    high = mid - 1;
   }
   else
   {
    low = mid + 1;
   }
  }
  return -1;
 }

 vector<int> twoSum(vector<int> &numbers, int target)
 {
  vector<int> ans(2, 0);
  for (int i = 1; i < numbers.size(); i++)
  {
   // num1 + num2 == target
   int num1 = target - numbers[i];
   int indexOfNum1 = findNumber(numbers, num1, 0, i - 1);
   if (indexOfNum1 != -1)
   {
    // 1 based indexing
    ans[0] = indexOfNum1 + 1;
    ans[1] = i + 1;
   }
  }
  return ans;
 }
};