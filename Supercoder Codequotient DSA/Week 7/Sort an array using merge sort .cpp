#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m] and Second subarray is arr[m+1..r]
void merge(int array[], int l, int m, int r)
{
 int i, j, k;
 int n1 = m - l + 1;
 int n2 = r - m;
 int left[n1], right[n2];
 for (i = 0; i < n1; i++)
 {
  left[i] = array[l + i];
 }
 for (j = 0; j < n2; j++)
 {
  right[j] = array[m + 1 + j];
 }
 i = 0, j = 0, k = l;
 while (i < n1 && j < n2)
 {
  if (left[i] <= right[j])
  {
   array[k++] = left[i++];
  }
  else
  {
   array[k++] = right[j++];
  }
 }

 while (i < n1)
 {
  array[k++] = left[i++];
 }

 while (j < n2)
 {
  array[k++] = right[j++];
 }
}

/* l is for left index and r is right index of the sub-array of arr to be sorted */
void mergeSort(int array[], int l, int r)
{
 if (l < r)
 {
  int mid = (l + r) / 2;

  mergeSort(array, l, mid);
  mergeSort(array, mid + 1, r);

  merge(array, l, mid, r);
 }
}