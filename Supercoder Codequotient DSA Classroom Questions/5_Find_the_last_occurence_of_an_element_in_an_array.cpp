#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int getLastOccurence(int arr[], int n, int x)
{
 int l = 0, r = n - 1;
 while (l <= r)
 {
  int mid = (l + r) / 2;
  if (x == arr[mid])
  {
   if (mid + 1 <= r && arr[mid + 1] == x)
   {
    l = mid + 1;
   }
   else
   {
    return mid;
   }
  }
  else if (x > arr[mid])
  {
   l = mid + 1;
  }
  else
  {
   r = mid - 1;
  }
 }
 return -1;
}
