#include <bits/stdc++.h>
#include <climits>
#include <algorithm>
using namespace std;

//! Approach 1

#include <algorithm>
vector<int> reduceArray(vector<int> arr)
{
 int n = arr.size();
 int remainingSticks = n;
 sort(arr.begin(), arr.end());
 vector<int> reduceOperations;
 for (int i = 0; i < n; i++)
 {
  reduceOperations.push_back(remainingSticks);
  int count = 1; /* counting arr[i] */
  while (i + 1 < n && arr[i] == arr[i + 1])
  {
   count++;
   i++;
  }
  remainingSticks -= count;
 }
 return reduceOperations;
}

//! Approach 2
/*
int findMin(vector<int> arr, int n)
{
 int min_element = INT_MAX;
 for (int i = 0; i < n; i++)
 {
  if (arr[i] != 0)
  {
   min_element = min(min_element, arr[i]);
  }
 }
 return min_element;
}

int findCount(vector<int> &arr, int n, int k)
{
 int count = 0;
 for (int i = 0; i < n; i++)
 {
  if (arr[i] == k)
  {
   count++;
   arr[i] = 0;
  }
 }
 return count;
}

vector<int> reduceArray(vector<int> arr)
{
 // Write your code here
 vector<int> reduce_info;
 int size = arr.size();
 int leftToReduce = size;
 while (leftToReduce > 0)
 {
  reduce_info.push_back(leftToReduce);
  int min_element = findMin(arr, size);
  int count_of_min_element = findCount(arr, size, min_element);
  leftToReduce -= count_of_min_element;
 }
 return reduce_info;
}
*/

int main()
{
 int n = 0, i;
 cin >> n;

 vector<int> arr(n);
 for (i = 0; i < n; i++)
  cin >> arr[i];

 vector<int> res;
 res = reduceArray(arr);
 for (i = 0; i < res.size(); i++)
  cout << res[i] << endl;

 return 0;
}