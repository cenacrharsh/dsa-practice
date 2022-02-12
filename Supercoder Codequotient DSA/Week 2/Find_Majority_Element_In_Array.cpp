#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int getFirstOcc(int arr[], int l, int r, int k)
{
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
    return mid;
   }
  }
  else if (k < arr[mid])
  {
   r = mid - 1;
  }
  else
  {
   l = mid + 1;
  }
 }
 return -1;
}

int getLastOcc(int arr[], int l, int r, int k)
{
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
    return mid;
   }
  }
  else if (k < arr[mid])
  {
   r = mid - 1;
  }
  else
  {
   l = mid + 1;
  }
 }
 return -1;
}

int getCount(int arr[], int k, int n)
{
 int first = getFirstOcc(arr, 0, n - 1, k);
 if (first == -1)
 {
  return 0;
 }
 int last = getLastOcc(arr, 0, n - 1, k);
 return (last - first + 1);
}

int getMajorityElement(int array[], int size)
{
 // Enter Your Code
 sort(array, array + size);
 int maxCount = INT_MIN;
 int ans = -1;
 for (int i = 0; i < size; i++)
 {
  int tempCount = getCount(array, array[i], size);
  if (tempCount > maxCount)
  {
   maxCount = tempCount;
   ans = array[i];
  }
 }
 int requiredCount = size / 2;
 if (maxCount > requiredCount)
 {
  return ans;
 }
 else
 {
  return -1;
 }
}