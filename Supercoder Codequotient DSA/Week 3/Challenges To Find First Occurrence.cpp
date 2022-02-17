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

long solveChallenges(int N, int arr[], int K, int challenges[])
{
 // Write your code here
 long totalSum = 0;
 for (int i = 0; i < K; i++)
 {
  int index = findFirstOccurence(arr, N, challenges[i]);
  totalSum += index;
 }
 return totalSum;
}