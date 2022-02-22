#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

//! Approach 1 - Using Binary Search

/*
> Time Complexity: O(log n)
> Space Complexity: O(1)
*/

int rotationCount(int arr[], int size)
{
 // Write your code here
 int l = 0, r = size - 1;

 while (l <= r)
 {
  // if array already sorted
  if (arr[l] <= arr[r])
  {
   return l;
  }

  int mid = (l + r) / 2;
  int prev = (mid - 1 + size) % size;
  int next = (mid + 1) % size;
  if (arr[prev] > arr[mid] && arr[next] > arr[mid])
  {
   return mid;
  }
  else if (arr[mid] > arr[r])
  {
   l = mid + 1;
  }
  else if (arr[mid] < arr[r])
  {
   r = mid - 1;
  }
 }
 return -1;
}

//! Approach 2 - Using Linear Search

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

int rotationCount(int arr[], int size)
{
 // Write your code here
 int min_index = 0;
 for (int i = 0; i < size; i++)
 {
  if (arr[i] < arr[min_index])
  {
   min_index = i;
  }
 }
 return min_index;
}