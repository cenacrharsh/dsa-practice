//# Tutorial: https://www.youtube.com/watch?v=50nn3bA1BT4

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

/*
 * Complete the 'pickMGifts' function below.
 * @params
 *  m -> number of childrens
 *  arr -> vector of integers denoting N boxes, each box containing different number of chocolates
 *
 * @return
 *   The minimum imbalance possible with N boxes and M children.
 */

int pickMGifts(int m, vector<int> arr)
{
 // first we sort the array to find max & min in a window with O(1) time complexity
 int n = arr.size();
 sort(arr.begin(), arr.end());
 int minDifference = INT_MAX;
 int minChoclate = INT_MAX;
 int maxChoclate = INT_MIN;
 for (int start = 0; start < n; start++)
 {
  int end = start + m - 1;
  if (end <= n - 1)
  {
   minChoclate = arr[start];
   maxChoclate = arr[end];
   int tempDifference = maxChoclate - minChoclate;
   minDifference = min(minDifference, tempDifference);
  }
  else
  {
   break;
  }
 }
 return minDifference;
}

int main()
{
 int m;
 cin >> m;
 int arr_count;
 cin >> arr_count;
 vector<int> arr(arr_count);
 for (int i = 0; i < arr_count; i++)
 {
  cin >> arr[i];
 }
 int result = pickMGifts(m, arr);
 cout << result << "\n";
 return 0;
}