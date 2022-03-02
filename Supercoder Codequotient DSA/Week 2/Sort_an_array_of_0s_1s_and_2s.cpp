#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

void sorting012Array(int a[], int n)
{
 // Write your code here
 int l = 0, mid = 0, h = n - 1;
 while (mid <= h)
 {
  if (a[mid] == 0)
  {
   swap(a[l++], a[mid++]);
  }
  else if (a[mid] == 1)
  {
   mid++;
  }
  else if (a[mid] == 2)
  {
   swap(a[mid], a[h--]);
  }
 }
}

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

void sorting012Array(int arr[], int n)
{
 int count0 = 0, count1 = 0, count2 = 0;

 for (int i = 0; i < n; i++)
 {
  if (arr[i] == 0)
  {
   count0++;
  }
  else if (arr[i] == 1)
  {
   count1++;
  }
  else if (arr[i] == 2)
  {
   count2++;
  }
 }

 int i = 0;
 while (count0--)
 {
  arr[i++] = 0;
 }
 while (count1--)
 {
  arr[i++] = 1;
 }
 while (count2--)
 {
  arr[i++] = 2;
 }
}

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

void sorting012Array(int a[], int n)
{
 // Write your code here
 int l = 0, mid = 0, h = n - 1;

 while (mid <= h)
 {
  if (a[mid] == 0)
  {
   swap(a[l++], a[mid++]);
  }
  else if (a[mid] == 1)
  {
   mid++;
  }
  else if (a[mid] == 2)
  {
   swap(a[mid], a[h--]);
  }
 }
}