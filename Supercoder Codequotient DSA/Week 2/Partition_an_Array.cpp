#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

//! New Array and 2 traversals

/*
> Time Complexity: O(n+n) => O(n)
> Space Complexity: O(n)
*/

void partitionArray(int arr[], int n, int x)
{
 int res[n];
 int j = 0;

 for (int i = 0; i < n; i++)
 {
  if (arr[i] <= x)
  {
   res[j++] = arr[i];
  }
 }

 for (int i = 0; i < n; i++)
 {
  if (arr[i] > x)
  {
   res[j++] = arr[i];
  }
 }
}

//! New Array and 1 traversal

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

void partitionArray2(int arr[], int n, int x)
{
 int res[n];
 int j = 0, k = n - 1;

 for (int i = 0; i < n; i++)
 {
  if (arr[i] <= x)
  {
   res[j++] = arr[i];
  }
  else
  {
   res[k--] = arr[i];
  }
 }
}

//! No new array and one traversal, using 2 ptrs

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

void partitionArray3(int arr[], int n, int x)
{
 int j = 0;
 for (int i = 0; i < n; i++)
 {
  if (arr[i] <= x)
  {
   swap(arr[j], arr[i]);
   j++;
  }
 }
}