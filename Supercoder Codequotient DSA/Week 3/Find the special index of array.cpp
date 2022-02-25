#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

//! Approach 1 -> suffix sum array and prefix sum variable
int specialIndex(vector<int> arr)
{
  // Write your code here
  int n = arr.size();
  int ans = -1;
  int prefixSum = 0;
  vector<int> suffixSum(n);
  suffixSum[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    suffixSum[i] = suffixSum[i + 1] + arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    prefixSum += arr[i];
    int suffix_sum = suffixSum[i];
    if (prefixSum == suffixSum[i])
    {
      ans = i;
    }
  }
  return ans;
}

//! Approach 2 -> suffix sum array and prefix sum array

/*
 * Complete the 'specialIndex' function below.
 * @params
 * arr -> An vector of integers
 *
 * @return
 * The index of an array such that the sum of elements at
 * lower indices is equal to the sum of elements at higher indices.
 */

int specialIndex(vector<int> arr)
{
  int n = arr.size();
  int prefixSum[n], suffixSum[n];

  //! prefixSum contains sum of elements till i - 1
  prefixSum[0] = 0;
  for (int i = 1; i < n; i++)
  {
    prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
  }

  //! suffixSum contains sum of elements from i + 1
  suffixSum[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--)
  {
    suffixSum[i] = suffixSum[i + 1] + arr[i + 1];
  }

  /*
  for(int i=0;i<n;i++)
  {
    cout << "prefixSum[i]: " << prefixSum[i] << " suffixSum[i]: " << suffixSum[i] << endl;
  }
  */

  int ans = -1;
  for (int i = 0; i < n; i++)
  {
    if (prefixSum[i] == suffixSum[i])
    {
      ans = i;
      break;
    }
  }
  return ans;
}