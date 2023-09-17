#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int findFirstPos(int arr[], int n, int k, int l, int r)
{
 int index = -1;
 while (l <= r)
 {
  int mid = l + (r - l) / 2;
  if (arr[mid] == k)
  {
   if (mid - 1 >= l && arr[mid - 1] == k)
   {
    r = mid - 1;
   }
   else
   {
    index = mid;
    break;
   }
  }
  else if (k < arr[mid])
  {
   r = mid - 1;
  }
  else if (k > arr[mid])
  {
   l = mid + 1;
  }
 }
 return index;
}

int findLastPos(int arr[], int n, int k, int l, int r)
{
 int index = -1;
 while (l <= r)
 {
  int mid = l + (r - l) / 2;
  if (arr[mid] == k)
  {
   if (mid + 1 <= r && arr[mid + 1] == k)
   {
    l = mid + 1;
   }
   else
   {
    index = mid;
    break;
   }
  }
  else if (k < arr[mid])
  {
   r = mid - 1;
  }
  else if (k > arr[mid])
  {
   l = mid + 1;
  }
 }
 return index;
}

int countOccurences(int arr[], int n, int X)
{
 pair<int, int> position;
 position.first = findFirstPos(arr, n, X, 0, n - 1);
 position.second = findLastPos(arr, n, X, 0, n - 1);

 if (position.first == -1 && position.second == -1)
 {
  return 0;
 }
 else if (position.first == -1 || position.second == -1)
 {
  return 1;
 }
 else
 {
  return position.second - position.first + 1;
 }
}