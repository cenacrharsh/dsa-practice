#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

//! Randomized Quick Sort

/*
> Time Complexity: O(n * log n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 int randomPartition(vector<int> &nums, int l, int r)
 {
  // select random element of array :
  srand(time(NULL));
  int pivot = l + rand() % (r - l);
  swap(nums[pivot], nums[r]);
  return partition(nums, l, r);
 }

 int partition(vector<int> &nums, int l, int r)
 {
  int pivot = nums[r];

  int j = l;

  for (int i = l; i <= r; i++)
  {
   if (nums[i] <= pivot)
   {
    swap(nums[i], nums[j]);
    j++;
   }
  }
  return j - 1;
 }

 void quickSort(vector<int> &nums, int l, int r)
 {
  if (l < r)
  {
   int pivot_index = randomPartition(nums, l, r);

   quickSort(nums, l, pivot_index - 1);
   quickSort(nums, pivot_index + 1, r);
  }
 }

 vector<int> sortArray(vector<int> &nums)
 {
  quickSort(nums, 0, nums.size() - 1);
  return nums;
 }
};