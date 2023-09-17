#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Negative Array

/*
Algorithm

We can save the space used in the last approach, if we can somehow, include the information regarding the duplicacy of an element or absence of an element in the numsnums array. Let's see how this can be done.

We know that all the elements in the given numsnums array are positive, and lie in the range 11 to nn only. Thus, we can pick up each element ii from numsnums. For every number ii picked up, we can invert the element at the index \left|i\right|∣i∣. By doing so, if one of the elements jj occurs twice, when this number is encountered the second time, the element nums[\left|i\right|]nums[∣i∣] will be found to be negative. Thus, while doing the inversions, we can check if a number found is already negative, to find the duplicate number.

After the inversions have been done, if all the elements in numsnums are present correctly, the resultant numsnums array will have all the elements as negative now. But, if one of the numbers, j is missing, the element at the j^{th} index will be positive. This can be used to determine the missing number.
*/

class Solution
{
public:
 vector<int> findErrorNums(vector<int> &nums)
 {
  int missing = -1, duplicate = -1;

  for (int n : nums)
  {
   if (nums[abs(n) - 1] < 0)
   {
    duplicate = abs(n);
   }
   else
   {
    nums[abs(n) - 1] *= -1;
   }
  }

  for (int i = 0; i < nums.size(); i++)
  {
   if (nums[i] > 0)
   {
    missing = i + 1;
   }
  }

  vector<int> ans(2);
  ans[0] = duplicate;
  ans[1] = missing;

  return ans;
 }
};

//! Using Sorting

/*
> Time Complexity: O(n logn)
> Space Complexity: O(log n)
*/

/*
public class Solution {
    public int[] findErrorNums(int[] nums) {
        Arrays.sort(nums);
        int dup = -1, missing = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1])
                dup = nums[i];
            else if (nums[i] > nums[i - 1] + 1)
                missing = nums[i - 1] + 1;
        }
        return new int[] {dup, nums[nums.length - 1] != nums.length ? nums.length : missing};
    }
}
*/

//! Using Hashmap/Extra Array

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

/*
public
class Solution
{
public
 int[] findErrorNums(int[] nums)
 {
  Map<Integer, Integer> map = new HashMap();
  int dup = -1, missing = 1;
  for (int n : nums)
  {
   map.put(n, map.getOrDefault(n, 0) + 1);
  }
  for (int i = 1; i <= nums.length; i++)
  {
   if (map.containsKey(i))
   {
    if (map.get(i) == 2)
     dup = i;
   }
   else
    missing = i;
  }
  return new int[]{dup, missing};
 }
}

public class Solution
{
public
 int[] findErrorNums(int[] nums)
 {
  int[] arr = new int[nums.length + 1];
  int dup = -1, missing = 1;
  for (int i = 0; i < nums.length; i++)
  {
   arr[nums[i]] += 1;
  }
  for (int i = 1; i < arr.length; i++)
  {
   if (arr[i] == 0)
    missing = i;
   else if (arr[i] == 2)
    dup = i;
  }
  return new int[]{dup, missing};
 }
}
*/