#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Binary Search

/*
> Time Complexity: O(log n)
> Space Complexity: O(1)
*/

/*
For odd numbers (e.g., 1, 3, 5, 7, 9), mid^1 equals to mid - 1
For example: 3 ^ 1 = 0011 ^ 0001 = 0010 = 2

For even numbers (e.g., 2, 4, 6, 8, 10), mid^1 equals to mid + 1
For example: 6 ^ 1 = 0110 ^ 0001 = 0111 = 7
*/

/*
Optimal Approach: (Binary Search)

We will use the fact that the vector is sorted.

Observation: If you divide the array in two parts, PART A: where elements are before target element and PART B: where elements are after target element then:

a. In PART A, the first instance of element occurs at even index and the second instance of the element occurs at odd index.

b. In PART B, the first instance of element occurs at odd index and the second instance of the element occurs at even index.

c. You can visualize using following example:

index:   0 1 2 3 4 5 6 7 8
vector: [1,1,2,3,3,4,4,8,8]
             👆 (Target element is 2 since it appears once)
In this example, before 2 every first instance of element occurs at even index and second instance at odd index (see element 1) and after 2 every first instance of element occurs at odd index and second instance at even index (see element 3, 4 and 8).

So from the above observation we will apply binary search on our array, and if we are on the PART - B side of array, we go to left, otherwise we go right.
*/

class Solution
{
public:
 int singleNonDuplicate(vector<int> &nums)
 {
  int low = 0, high = nums.size() - 2;

  while (low <= high)
  {

   int mid = low + (high - low) / 2;

   // If we are on left side, move right
   if (nums[mid] == nums[mid ^ 1])
    low = mid + 1;
   // if we are on right side, move left
   else
    high = mid - 1;
  }

  return nums[low];
 }
};

//* Checking nums[ mid ] == nums[ mid^1 ] is equivalent to checking,
//* (mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1])

// mid^1 explanation:
// If mid is odd then (mid^1) will always be the even number before mid
// If mid is even then (mid^1) will always be the odd number after mid

// And hence I am able to check whether mid is in left half or right half as:

// Suppose mid is odd: then mid^1 will give even number before it,
// then if nums[mid] == nums[mid^1]
// then 1st instance at even (mid^1) and 2nd instance at odd (mid),
// hence we are on left side otherwise we are on right side.

// Suppose mid is even: then mid^1 will give odd number after it,
// then if nums[mid] == nums[mid^1]
// then 1st instance at even (mid) and 2nd instance at odd (mid^1),
// hence we are on left side otherwise we are on right side

//! Using XOR

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 int singleNonDuplicate(vector<int> &nums)
 {
  int sum = 0;
  for (int i : nums)
  {
   sum ^= i;
  }
  return sum;
 }
};