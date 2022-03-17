#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimized Approach

/*
> Time Complexity: O(n + m)
> Space Complexity: O(n + m)
*/

int *mergeArrays(int a[], int b[], int asize, int bsize)
{
 // Write your code here
 int *ans = new int[asize + bsize];
 int i = 0, j = 0, k = 0;
 while (i < asize && j < bsize)
 {
  if (a[i] <= b[j])
  {
   ans[k++] = a[i++];
  }
  else
  {
   ans[k++] = b[j++];
  }
 }

 while (i < asize)
 {
  ans[k++] = a[i++];
 }

 while (j < bsize)
 {
  ans[k++] = b[j++];
 }

 return ans;
}

//! Brute Force

/*
> Time Complexity: O(n + m * log(n + m))
> Space Complexity: O(n + m)
*/

int *mergeArrays(int a[], int b[], int asize, int bsize)
{
 // Write your code here
 int *ans = new int[asize + bsize];
 int j = 0;

 for (int i = 0; i < asize; i++)
 {
  ans[j++] = a[i];
 }

 for (int i = 0; i < bsize; i++)
 {
  ans[j++] = b[i];
 }

 sort(ans, ans + j);

 return ans;
}

int main()
{
 int i, k, size = 0, size1 = 0, *final;
 cin >> size;
 int a[size];
 for (i = 0; i < size; i++)
  cin >> a[i];

 cin >> size1;
 int b[size1];
 for (i = 0; i < size1; i++)
  cin >> b[i];

 final = mergeArrays(a, b, size, size1);

 for (i = 0; i < (size + size1); i++)
  cout << final[i] << " ";

 return 0;
}
