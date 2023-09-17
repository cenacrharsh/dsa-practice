#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=jZcAldZP1ag

//! use array containing count of each number

/*
 * i == j == k, nC3 => n! / (3! * (n-3)!)
 * i == j != k, nC2 * c[k] => (n! / 2! * (n-2)!) * c[k]
 * i != j != k, c[i] * c[j] * c[k]
 */

class Solution
{
public:
 int threeSumMulti(vector<int> &arr, int target)
 {
  int mod = 1000000007;
  long result = 0;
  long count[101] = {0};
  for (int n : arr)
  {
   count[n]++;
  }
  for (int i = 0; i <= 100; i++)
  {
   for (int j = i; j <= 100; j++)
   {
    int k = target - i - j;
    if (k < 0 || k > 100)
     continue;

    if (i == j && j == k)
    {
     result += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
    }
    else if (i == j && j != k)
    {
     result += (count[i] * (count[i] - 1) / 2) * count[k];
    }
    else if (i < j && j < k) // to avoid repetition we use i<j<k and not i != j && i != k
    {
     result += count[i] * count[j] * count[k];
    }
   }
  }
  return result % mod;
 }
};

//! 2 loops

/*
> Time Complexity: O(n2)
> Space Complexity: O(1)
*/

class Solution
{
public:
 int threeSumMulti(vector<int> &arr, int target)
 {
  int mod = 1000000007;
  long result = 0;
  for (int i = 0; i < arr.size(); i++)
  {
   int count[101] = {0};
   for (int j = i + 1; j < arr.size(); j++)
   {
    int k = target - arr[i] - arr[j];
    if (k >= 0 && k <= 100 && count[k] > 0)
    {
     result += count[k];
     result %= mod;
    }
    count[arr[j]]++;
   }
  }
  return result;
 }
};