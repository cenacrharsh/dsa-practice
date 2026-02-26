#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int findFirstOccurence(int arr[], int N, int target)
{
 int l = 0, r = N - 1;
 while (l <= r)
 {
  int mid = (l + r) / 2;
  if (arr[mid] == target)
  {
   if (mid - 1 >= l && arr[mid - 1] == target)
   {
    r = mid - 1;
   }
   else
   {
    return mid;
   }
  }
  else if (target > arr[mid])
  {
   l = mid + 1;
  }
  else if (target < arr[mid])
  {
   r = mid - 1;
  }
 }
 return -1;
}

int getLastOccurence(int arr[], int N, int target)
{
 int l = 0, r = N - 1;
 while (l <= r)
 {
  int mid = (l + r) / 2;
  if (target == arr[mid])
  {
   if (mid + 1 <= r && arr[mid + 1] == target)
   {
    l = mid + 1;
   }
   else
   {
    return mid;
   }
  }
  else if (target > arr[mid])
  {
   l = mid + 1;
  }
  else if (target < arr[mid])
  {
   r = mid - 1;
  }
 }
 return -1;
}

int findCount(int arr[], int N, int target)
{
 int firstOcc = findFirstOccurence(arr, N, target);
 int lastOcc = getLastOccurence(arr, N, target);
 int count = 0;
 if (firstOcc != -1 && lastOcc != -1)
 {
  count = lastOcc - firstOcc + 1;
 }
 else if (firstOcc == -1 && lastOcc == -1)
 {
  count = 0;
 }
 else if (firstOcc == -1 || lastOcc == -1)
 {
  count = 1;
 }
 // cout << target << " firstOcc: " << firstOcc << " lastOcc: " << lastOcc << " and count: " << count << endl;
 return count;
}

long solveChallenges(int N, int arr[], int K, int challenges[])
{
 // Write your code here
 long totalSum = 0;
 for (int i = 0; i < K; i++)
 {
  int index = findCount(arr, N, challenges[i]);
  totalSum += index;
 }
 return totalSum;
}

int main()
{
 int i, k, size = 0, size1 = 0;
 cin >> size;
 int a[size];
 for (i = 0; i < size; i++)
  cin >> a[i];

 cin >> size1;
 int b[size1];
 for (i = 0; i < size1; i++)
  cin >> b[i];

 long final = solveChallenges(size, a, size1, b);
 cout << final;

 return 0;
}