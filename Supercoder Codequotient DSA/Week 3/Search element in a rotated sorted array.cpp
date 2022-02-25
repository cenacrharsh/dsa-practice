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