#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int maxDifference(int arr[], int n)
{
 int currentMinimumElement = arr[0];
 int maxDifference = -1;
 for (int i = 1; i < n; i++)
 {
  if (currentMinimumElement != arr[i])
  {
   int tempDifference = arr[i] - currentMinimumElement;
   maxDifference = max(maxDifference, tempDifference);

   // updating the minimum element
   currentMinimumElement = min(currentMinimumElement, arr[i]);
  }
 }
 return maxDifference;
}