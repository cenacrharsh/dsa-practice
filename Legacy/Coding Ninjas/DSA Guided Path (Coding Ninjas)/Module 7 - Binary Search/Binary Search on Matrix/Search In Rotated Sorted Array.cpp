#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int findPosition(vector<int> &arr, int n, int k)
{
 // Write your code here.
 // Return the position of K in ARR else return -1.
 int l = 0;
 int r = n - 1;
 int index = -1;
 while (l <= r)
 {
  int mid = l + (r - l) / 2;
  if (k == arr[mid])
  {
   index = mid;
   break;
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
 return index;
}
