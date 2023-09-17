// Tutorial: https://www.youtube.com/watch?v=Dxv_kCAYOk4&t=226s
/*
> No element can be lower/smaller than the element before it
Valid Non Decreasing Arrays:
           _
_ _ _, _ -

Invalid: - _ -
*/

/*
> i - 2, i - 1, i

* now if i < i - 1,
* 2 cases arise:
* first: i - 2 is upper than i, then we have no choice but to go upto i - 1 level so that now i is above i - 2 and i is in level with i - 1 ( which was already >= i - 2)

* second: i - 2 is lower than  i, then for current case we can both take i up to i - 1 level or bring i - 1 down to i level,but if we go up then elements coming after i can be down to i but > i - 1, in that case our choice was wrong, this can be avoided if we bring i - 1 down to i and so any further element unless lower than i will give right ans
*/

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution
{
public:
 bool checkPossibility(vector<int> &nums)
 {
  int count = 0;
  for (int i = 1; i < nums.size(); i++)
  {
   if (nums[i] < nums[i - 1])
   {
    // i - 2 is lower than i
    if (i == 1 || nums[i - 2] <= nums[i])
    {
     nums[i - 1] = nums[i];
     count++;
    }
    // i - 2 is above i
    else
    {
     nums[i] = nums[i - 1];
     count++;
    }
   }
  }
  return (count <= 1);
 }
};