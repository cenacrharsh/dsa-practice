#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int searchRotatedSortedArray(int arr[], int n, int k)
{
 // Write your code here
 int l = 0, r = n - 1;
 while (l <= r)
 {
  int mid = (l + r) / 2;
  if (k == arr[mid])
  {
   return mid;
  }
  else if (arr[l] <= arr[mid])
  {
   if (k >= arr[l] && k < arr[mid])
   {
    r = mid - 1;
   }
   else
   {
    l = mid + 1;
   }
  }
  else if (arr[mid] <= arr[r])
  {
   if (k > arr[mid] && k <= arr[r])
   {
    l = mid + 1;
   }
   else
   {
    r = mid - 1;
   }
  }
 }
 return -1;
}

//! Approach 2 - Using Binary Search

/*
> Time Complexity: O(2 * log n)
> Space Complexity: O(1)
*/

int findPivot(int arr[], int n)
{
 int l = 0, r = n - 1;
 while (l <= r)
 {
  if (arr[l] <= arr[r])
  {
   return l;
  }
  int mid = (l + r) / 2;
  int prev = (mid - 1 + n) % n;
  int next = (mid + 1) % n;
  if (arr[prev] > arr[mid] && arr[next] > arr[mid])
  {
   return mid;
  }
  else if (arr[mid] < arr[r])
  {
   r = mid - 1;
  }
  else if (arr[mid] > arr[r])
  {
   l = mid + 1;
  }
 }
 return -1;
}

int binarySearch(int arr[], int k, int l, int r)
{
 while (l <= r)
 {
  int mid = (l + r) / 2;
  if (k == arr[mid])
  {
   return mid;
  }
  else if (k > arr[mid])
  {
   l = mid + 1;
  }
  else if (k < arr[mid])
  {
   r = mid - 1;
  }
 }
 return -1;
}

int searchRotatedSortedArray(int arr[], int n, int k)
{
 int pivot = findPivot(arr, n);
 // if k > arr[n-1], then element lies to left of pivot
 if (k > arr[n - 1])
 {
  return binarySearch(arr, k, 0, pivot - 1);
 }
 // if k <= arr[n-1], then element lies to right of pivot
 else
 {
  return binarySearch(arr, k, pivot, n - 1);
 }
}

//! Approach 3 - Using Linear Search

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

int searchRotatedSortedArray(int arr[], int n, int k)
{
 // Write your code here
 for (int i = 0; i < n; i++)
 {
  if (arr[i] == k)
  {
   return i;
  }
 }
 return -1;
}