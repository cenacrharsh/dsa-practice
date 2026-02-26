#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//! Approach 1

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

int findSecondLargest(int n, vector<int> &arr)
{
 // Write your code here.
 int largest = INT_MIN;
 int second_largest = INT_MIN;
 for (int i = 0; i < n; i++)
 {
  if (arr[i] > largest)
  {
   second_largest = largest;
   largest = arr[i];
  }
  //> If an element is smaller than largest and smaller than second largest.
  else if (arr[i] > second_largest && arr[i] != largest)
  {
   second_largest = arr[i];
  }
 }
 if (second_largest == INT_MIN)
 {
  return -1;
 }
 else
 {
  return second_largest;
 }
}

//! Approach 2: 2 traversals

/*
> Time Complexity: O(2n)
> Space Complexity: O(1)
*/

#include <algorithm>
int findSecondLargest(int n, vector<int> &arr)
{
 // Write your code here
 int largest = INT_MIN;
 int second_largest = INT_MIN;
 for (int i = 0; i < n; i++)
 {
  largest = max(largest, arr[i]);
 }
 for (int i = 0; i < n; i++)
 {
  if (arr[i] != largest)
  {
   second_largest = max(second_largest, arr[i]);
  }
 }
 if (second_largest == INT_MIN)
 {
  return -1;
 }
 else
 {
  return second_largest;
 }
}

//! Approach 3: Sorting

/*
> Time Complexity: O(n*logn)
> Space Complexity: O(1)
*/

int findSecondLargest(int n, vector<int> &arr)
{
 // Sort the array in decending order.
 sort(arr.begin(), arr.end(), greater<int>());

 for (int i = 1; i < n; i++)
 {
  // If the element is not equal to first largest element.
  if (arr[i] != arr[i - 1])
  {
   return arr[i];
  }
 }

 return -1;
}
