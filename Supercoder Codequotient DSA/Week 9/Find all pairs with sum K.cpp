#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int getPairsCount(int arr[], int n, int k)
{
 // Write your code here
 unordered_map<int, int> unique;
 int count = 0;
 for (int i = 0; i < n; i++)
 {
  int temp_count = unique[k - arr[i]];
  count += temp_count;
  unique[arr[i]]++;
 }
 return count;
}
