#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=_yGf2rxwZlA, https://www.youtube.com/watch?v=xmguZ6GbatA

//! Striver

class Solution
{
public:
 int maxLen(vector<int> &A, int n)
 {
  // Your code here
  unordered_map<int, int> profitMap;
  int maxDays = 0;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
   sum += A[i];
   if (sum == 0)
   {
    maxDays = i + 1;
   }
   else
   {
    if (profitMap.find(sum) != profitMap.end())
    {
     maxDays = max(maxDays, i - profitMap[sum]);
    }
    else
    {
     profitMap[sum] = i;
    }
   }
  }
  return maxDays;
 }
};

//! Sumeet Sir
int maxConsecutiveDays(int profit[], int N)
{
 // Write your code here
 unordered_map<int, int> profitMap; // profit -> index
 int overallProfit = 0;
 int i = -1;
 profitMap[overallProfit] = i;
 int maxDays = 0;
 while (i < N - 1)
 {
  i++;

  overallProfit += profit[i];

  if (profitMap.find(overallProfit) != profitMap.end())
  {
   int days = i - profitMap[overallProfit];
   maxDays = max(maxDays, days);
  }
  else
  {
   profitMap[overallProfit] = i;
  }
 }

 return maxDays;
}

//! Self
#include <unordered_map>
int maxConsecutiveDays(int profit[], int N)
{
 // Write your code here
 unordered_map<int, int> profitMap; // profit -> index/day
 profitMap[0] = 0;
 int overallProfit = 0;
 int maxDays = 0;
 for (int i = 0; i < N; i++)
 {
  overallProfit += profit[i];

  if (profitMap.find(overallProfit) != profitMap.end())
  {
   int days = i - profitMap[overallProfit] + 1;
   maxDays = max(maxDays, days);
  }
  else
  {
   profitMap[overallProfit] = i + 1; // 1 based indexing
  }
 }

 return maxDays;
}

int main()
{
 int n, k;
 cin >> n;
 int arr[n];
 int i;
 for (i = 0; i < n; i++)
  cin >> arr[i];
 cout << maxConsecutiveDays(arr, n);
 return 0;
}