#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int totalWater(int a[], int n)
{
 // Write your code here
 int l = 0;
 int r = n - 1;
 int leftMax = INT_MIN;
 int rightMax = INT_MIN;
 int water = 0;
 while (l <= r)
 {
  if (a[l] <= a[r])
  {
   if (a[l] >= leftMax)
   {
    leftMax = a[l];
   }
   else
   {
    water += leftMax - a[l];
   }
   l++;
  }
  else if (a[r] < a[l])
  {
   if (a[r] >= rightMax)
   {
    rightMax = a[r];
   }
   else
   {
    water += rightMax - a[r];
   }
   r--;
  }
 }
 return water;
}