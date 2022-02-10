#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

int removeDuplicates(int arr[], int n)
{
 int res[n];
 int i = 1, j = 1;

 while (i < n)
 {
  if (arr[i] != arr[i - 1])
  {
   res[j] = arr[i];
   j++;
  }
  i++;
 }

 for (i = 0; i < j; i++)
 {
  arr[i] = res[i];
 }

 return j; //* Size of updated array
}