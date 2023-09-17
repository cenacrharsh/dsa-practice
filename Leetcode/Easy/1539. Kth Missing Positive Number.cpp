#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Binary Search
/*
Intuition of this Problem:

First thing is how we can find number of mission element ?, so below is the magic statement :
arr[i] - (i + 1) : this statement will give us number of missing element before each arr[i] element, here i is nothing but mid used in the code.

For example, for the array [2,3,4,7,11], the number of missing positive integers before each element is [1,1,1,3,6] using above statement.

Second thing is after finding number of missing element before each element, how we can find that element which is missing ? :
We then use binary search to find the first index start such that the number of missing positive integers before arr[start] is greater than or equal to k. Once we have found this index start, we know that the kth smallest missing positive integer is between arr[start - 1] and arr[start].
 
Therefore, we can compute the kth smallest missing positive integer as arr[start - 1] + (k - (arr[start - 1] - (start - 1) - 1)) = start + k.

Let's break down this expression:

arr[start - 1] is the last element before the kth missing positive integer, so we start with this value.

(k - (arr[start - 1] - (start - 1) - 1)) is the number of missing positive integers between arr[start - 1] and the kth missing positive integer. We subtract arr[start - 1] - (start - 1) - 1 from k to account for the missing positive integers before arr[start - 1]. We then add this value to arr[start - 1] to get the kth missing positive integer.
*/
class Solution
{
public:
 int findKthPositive(vector<int> &arr, int k)
 {
  int low = 0, high = arr.size() - 1;
  while (low <= high)
  {
   int mid = low + (high - low) / 2;
   if (arr[mid] - (mid + 1) < k)
   {
    low = mid + 1;
   }
   else
   {
    // missing element >= k
    high = mid - 1;
   }
  }
  return low + k;
 }
};

//! Own Solution
class Solution
{
public:
 int findKthPositive(vector<int> &arr, int k)
 {
  unordered_map<int, int> m;
  for (auto it : arr)
  {
   m[it]++;
  }
  int count = 0, ans = 0, i = 1;
  while (true)
  {
   if (m.find(i) == m.end())
   {
    count++;
    if (count == k)
    {
     ans = i;
     break;
    }
   }
   i++;
  }
  return ans;
 }
};