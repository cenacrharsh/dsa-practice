#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

long solveQueries(int N, int arr[], int Q, int queries[])
{
 // Write your code here
 sort(arr, arr + N);
 long ans = 0;
 for (int i = 0; i < Q; i++)
 {
  int query = queries[i];
  int index = N - query;
  ans += arr[index];
 }
 return ans;
}