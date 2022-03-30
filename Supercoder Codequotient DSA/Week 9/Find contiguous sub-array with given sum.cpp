#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Hashmap

void findTheSubArray(int a[], int n, int sum)
{
 // Write your code here
 unordered_map<int, int> prefixSumMap; //* prefixSum -> index
 int prefixSum = 0;
 for (int j = 0; j < n; j++)
 {
  prefixSum += a[j];

  if (prefixSum == sum)
  {
   cout << "0"
        << " " << j << endl;
   return;
  }

  //* PS(i) = PS(j) - SUM
  if (prefixSumMap.find(prefixSum - sum) != prefixSumMap.end())
  {
   int i = prefixSumMap[prefixSum - sum];
   cout << (i + 1) << " " << j << endl;
   return;
  }

  prefixSumMap[prefixSum] = j;
 }
 cout << "-1" << endl;
}