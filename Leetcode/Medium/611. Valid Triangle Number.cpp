#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
Theorem: In a triangle, the length of any side is less than the sum of the other two sides.

So 3 side lengths a, b, c can form a Triangle if and only if a + b > c && a + c > b && b + c > a.

To make it simple, we can sort nums in increasing order.
Let nums[i] is the smallest element, nums[j] is the middle element, nums[k] is the largest element (i < j < k). Then nums[i], nums[j], nums[k] can form a valid Triangle if and only if nums[i] + nums[j] > nums[k].

Now, the problem become the same with 259. 3Sum Smaller

We fix nums[k], by iterating k in range [2..n-1], the answer is the total number of pairs (nums[i], nums[j]) for each nums[k], (i < j < k), so that nums[i] + nums[j] > nums[k].

We start withi = 0, j = k - 1
If nums[i] + nums[j] > nums[k] then:
There are j-i valid pairs, because in that case, when nums[k] and nums[j] are fixed, moving i to the right side always causes nums[i] + nums[j] > nums[k].
Try another nums[j] by decreasing j by one, so j -= 1.

Else if nums[i] + nums[j] <= nums[k] then:
Because nums[k] is fixed, to make the inequality correct, we need to increase sum of nums[i] + nums[j].
There is only one choice is to increase nums[i], so i += 1.
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
 int triangleNumber(vector<int> &nums)
 {
  sort(nums.begin(), nums.end());
  int ans = 0;
  for (int k = 2; k < nums.size(); k++)
  {
   int i = 0;
   int j = k - 1;
   while (i < j)
   {
    if (nums[i] + nums[j] > nums[k])
    {
     ans += j - i;
     j--;
    }
    else
    {
     i++;
    }
   }
  }
  return ans;
 }
};