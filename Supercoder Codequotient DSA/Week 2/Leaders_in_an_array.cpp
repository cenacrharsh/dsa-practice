
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

// Return the array that contains leader elements
vector<int> findTheLeaders(vector<int> arr)
{
 // Write your code here
 int n = arr.size();
 vector<int> leaders;
 int curr_max = arr[n - 1];
 leaders.insert(leaders.begin(), arr[n - 1]);
 for (int i = n - 2; i >= 0; i--)
 {
  if (arr[i] > curr_max)
  {
   /*
    * Syntax to insert elements at specified pos :
    > vector_name.insert (position, val)
   */
   leaders.insert(leaders.begin(), arr[i]);
  }
  curr_max = max(curr_max, arr[i]);
 }
 return leaders;
}