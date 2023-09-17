//# Tutorial: https://www.youtube.com/watch?v=gYmWHvRHu-s&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=69

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

/*
> Time Complexity: O(n * log n)
> Space Complexity: O(1)
*/

bool isPossible(vector<int> arr, int n, int m, int mid)
{
 int allocatedStudents = 1;
 int pages = 0;
 for (int i = 0; i < n; i++)
 {
  if (pages + arr[i] > mid)
  {
   allocatedStudents++;
   pages = arr[i];
  }
  else
  {
   pages += arr[i];
  }
 }
 if (allocatedStudents > m)
 {
  return false;
 }
 else
 {
  return true;
 }
}

int allocateBooks(vector<int> arr, int n, int m)
{
 // Write your code here.
 if (m > n)
 {
  return -1;
 }
 int low = arr[0];
 int high = 0;
 // to find minimum value and sum of all pages
 for (int i = 0; i < arr.size(); i++)
 {
  high = high + arr[i];
  low = max(low, arr[i]);
 }
 int minPages = -1;
 while (low <= high)
 {
  int mid = low + (high - low) / 2;
  if (isPossible(arr, n, m, mid))
  {
   minPages = mid;
   high = mid - 1;
  }
  else
  {
   low = mid + 1;
  }
 }
 return minPages;
}