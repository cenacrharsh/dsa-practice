#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

//! Merge Sort

/*
> Time Complexity: O(n * log n)
> Space Complexity: O(n)
*/

class Solution
{
public:
 void merge(vector<int> &nums, int l, int mid, int r)
 {
  int n1 = mid - l + 1;
  int n2 = r - mid;
  vector<int> left(n1);
  vector<int> right(n2);
  int i, j, k;
  for (i = 0; i < n1; i++)
  {
   left[i] = nums[l + i];
  }
  for (j = 0; j < n2; j++)
  {
   right[j] = nums[mid + 1 + j];
  }
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2)
  {
   if (left[i] < right[j])
   {
    nums[k++] = left[i++];
   }
   else
   {
    nums[k++] = right[j++];
   }
  }
  while (i < n1)
  {
   nums[k++] = left[i++];
  }
  while (j < n2)
  {
   nums[k++] = right[j++];
  }
 }
 void mergeSort(vector<int> &nums, int l, int r)
 {
  if (l < r)
  {
   int mid = (l + r) / 2;

   mergeSort(nums, l, mid);
   mergeSort(nums, mid + 1, r);

   merge(nums, l, mid, r);
  }
 }
 vector<int> sortArray(vector<int> &nums)
 {
  mergeSort(nums, 0, nums.size() - 1);
  return nums;
 }
};

//! Randomized Quick Sort

/*
> Time Complexity: O(n * log n) -> O(n2) in worst cases
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