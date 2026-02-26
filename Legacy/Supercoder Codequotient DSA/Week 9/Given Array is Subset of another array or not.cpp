#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int isSubsetorNot(int a[], int n, int b[], int m)
{
 // Write your code here
 if (m > n)
 {
  return false;
 }

 unordered_map<int, int> freq;
 for (int i = 0; i < n; i++)
 {
  freq[a[i]]++;
 }

 for (int i = 0; i < m; i++)
 {
  if (freq[b[i]] == 0)
  {
   return 0;
  }
  //* to handle repetition of elements
  freq[b[i]]--;
 }

 return 1;
}