#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

void permute(string currStr, vector<string> &permutations, int p, int n)
{
 int i;
 if (p == n - 1)
 {
  permutations.push_back(currStr);
 }
 else
 {
  for (i = p; i < n; i++)
  {
   swap(currStr[p], currStr[i]);
   permute(currStr, permutations, p + 1, n);
   swap(currStr[p], currStr[i]);
  }
 }
}

void allPermutations(string str, vector<string> &permutations)
{
 // Write your code here
 int n = str.size();
 permute(str, permutations, 0, n);
}