#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! 2 Pointers

/*
> We follow the below algorithm until one of the pointers reaches the other end of the array (here i represents the even pointer, and j represents the odd pointer):

* Keep incrementing i by 2 until either it reaches the other end, or an outlier (odd number at even index).

* Keep decrementing j by 2 until either it reaches the other end, or an outlier (even number at odd index).

* Swap nums[i] and nums[j]
*/

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 vector<int> sortArrayByParityII(vector<int> &nums)
 {
  for (int even = 0, odd = 1; even < nums.size(); even += 2, odd += 2)
  {
   // while loop breaks off at first odd no. at even pos
   while (even < nums.size() && nums[even] % 2 == 0)
    even += 2;

   // while loop breaks off at first even no. at odd pos
   while (odd < nums.size() && nums[odd] % 2 == 1)
    odd += 2;

   if (even < nums.size())
   {
    swap(nums[even], nums[odd]);
   }
  }
  return nums;
 }
};

//! Extra Vectors

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

class Solution
{
public:
 vector<int> sortEvenOdd(vector<int> &nums)
 {
  int n = nums.size();
  vector<int> odd;
  vector<int> even;
  for (int i = 0; i < nums.size(); i++)
  {
   if (i % 2 == 0)
   {
    even.push_back(nums[i]);
   }
   else
   {
    odd.push_back(nums[i]);
   }
  }
  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end(), greater<int>());

  vector<int> ans(n);
  int j = 0;
  for (int i = 0; i < even.size(); i++)
  {
   ans[j] = even[i];
   j += 2;
  }
  j = 1;
  for (int i = 0; i < odd.size(); i++)
  {
   ans[j] = odd[i];
   j += 2;
  }

  return ans;
 }
};