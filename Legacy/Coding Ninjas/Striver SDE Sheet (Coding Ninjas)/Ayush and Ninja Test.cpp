//# Tutorial: https://www.youtube.com/watch?v=gYmWHvRHu-s&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=69

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

/*
> Time Complexity: O(n * log n)
> Space Complexity: O(1)
*/

bool isPossible(vector<int> time, int n, int m, long long mid)
{
 long long allocatedDays = 1;
 long long pages = 0;
 for (int i = 0; i < m; i++)
 {
  if (pages + time[i] > mid)
  {
   allocatedDays++;
   pages = time[i];
  }
  else
  {
   pages += time[i];
  }
 }
 if (allocatedDays > n)
 {
  return false;
 }
 else
 {
  return true;
 }
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
 // Write your code here.
 if (n > m)
 {
  return -1;
 }
 int maxEle = time[0];
 long long high = 0;
 // to find minimum value and sum of all pages
 for (int i = 0; i < time.size(); i++)
 {
  high = high + time[i];
  maxEle = max(maxEle, time[i]);
 }

 long long low = maxEle;

 long long minTimeToStudy = -1;
 while (low <= high)
 {
  long long mid = low + (high - low) / 2;
  if (isPossible(time, n, m, mid))
  {
   minTimeToStudy = mid;
   high = mid - 1;
  }
  else
  {
   low = mid + 1;
  }
 }
 return minTimeToStudy;
}