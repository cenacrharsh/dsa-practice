#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int rotationCount(int arr[], int size)
{
 // Write your code here
 int n = size;
 int l = 0, r = n - 1;
 while (l <= r)
 {
  int mid = (l + r) / 2;
  int prev = (mid - 1 + n) % n;
  int next = (mid + 1) % n;
  if (arr[mid] < arr[prev] && arr[mid] < arr[next])
  {
   return mid;
  }
  else if (arr[mid] > arr[r])
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