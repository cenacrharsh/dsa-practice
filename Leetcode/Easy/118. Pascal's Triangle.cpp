#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=6FLvhQjZqvM

/*
> Time Complexity: O(N^2) => N*(N+1)/2
> Space Complexity: O(N)
*/

class Solution
{
public:
 vector<vector<int>> generate(int numRows)
 {
  // value of (i, j)th element = i-1Cj-1 (nCr), as we follow 0 based indexing hence -1
  // calculate value of [n * (n-1) *---* (n-k+1)]
  /*
  for(int i = 0; i < k; i++) {
      res *= (n - i);
      res /= (i + 1);
  }
  */
  vector<vector<int>> ans(numRows);
  for (int i = 0; i < numRows; i++)
  {
   // we know each row has elements = row number
   ans[i].resize(i + 1);

   // we also know first and last element of each row = 1
   ans[i][0] = ans[i][i] = 1;

   // traverse from 2nd element, to 2nd last element
   for (int j = 1; j < i; j++)
   {
    ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
   }
  }
  return ans;
 }
};