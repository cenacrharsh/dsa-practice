#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
Algorithm: Modified Insertion Sort
Loop from i = 1 to n - 1.
  a) If the current element is negative, do nothing.
  b) If the current element arr[i] is positvie, we
     insert it into sequence arr[0..i-1] such that
     all negative elements in arr[0..i-1] are shifted
     one position to their right and arr[i] is inserted
     at index of first negative element.
*/

void moveElements(int arr[], int n)
{
 // our approach is to push all positive elements to left side of array
 int key, j;
 for (int i = 1; i < n; i++)
 {
  key = arr[i];

  // if current element is negative do nothing
  if (key < 0)
  {
   continue;
  }

  /* if current element is positive, shift negative elements of arr[0..i-1],
  to one position to their right */
  j = i - 1;
  while (j >= 0 && arr[j] < 0)
  {
   arr[j + 1] = arr[j];
   j--;
  }
  // Put negative element at its correct position
  arr[j + 1] = key;
 }
}