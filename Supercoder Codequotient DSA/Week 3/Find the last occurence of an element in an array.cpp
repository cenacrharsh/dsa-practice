#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int lastIndexofK(int arr[], int n, int k)
{
 // Write Your Code Here
 int l = 0, r = n - 1;
 while (l <= r)
 {
  int mid = (l + r) / 2;
  if (arr[mid] == k)
  {
   if (mid + 1 <= r && arr[mid + 1] == k)
   {
    l = mid + 1;
   }
   else
   {
    return mid;
   }
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