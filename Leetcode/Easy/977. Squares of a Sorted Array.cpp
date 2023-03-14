#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=PN68qx-Qkdw

//! 2 pointers
class Solution
{
public:
 vector<int> sortedSquares(vector<int> &nums)
 {
  // 2 pointers -> one points to negative numbers, other to positive numbers
  int n = nums.size();
  int positive_pointer = 0;
  while (positive_pointer < n && nums[positive_pointer] < 0)
  {
   positive_pointer++;
  }
  int negative_pointer = positive_pointer - 1;
  // now positive_pointer points to first +ve number and negative_pointer points to last negative number, as squares in case of negative numbers would inc in backward manner eg. -4 < -1 but (-4)^2 > (-1)^2, but in positive numbers it inc in forward manner

  vector<int> sorted_squares(n, 0);
  int k = 0;
  while (negative_pointer >= 0 && positive_pointer < n)
  {
   if (nums[negative_pointer] * nums[negative_pointer] < nums[positive_pointer] * nums[positive_pointer])
   {
    sorted_squares[k] = nums[negative_pointer] * nums[negative_pointer];
    negative_pointer--;
   }
   else
   {
    sorted_squares[k] = nums[positive_pointer] * nums[positive_pointer];
    positive_pointer++;
   }
   k++;
  }

  while (negative_pointer >= 0)
  {
   sorted_squares[k] = nums[negative_pointer] * nums[negative_pointer];
   negative_pointer--;
   k++;
  }

  while (positive_pointer < n)
  {
   sorted_squares[k] = nums[positive_pointer] * nums[positive_pointer];
   positive_pointer++;
   k++;
  }

  return sorted_squares;
 }
};