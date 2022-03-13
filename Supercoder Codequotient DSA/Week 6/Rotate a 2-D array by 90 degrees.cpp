#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  int n;
  cin >> n;
  int mat[n][n];
  for (int i = 0; i < n; i++)
  {
   for (int j = 0; j < n; j++)
   {
    cin >> mat[i][j];
   }
  }
  // transpose
  for (int i = 0; i < n; i++)
  {
   for (int j = i; j < n; j++)
   {
    swap(mat[i][j], mat[j][i]);
   }
  }
  // reverse the transpose
  for (int i = 0; i < n; i++)
  {
   int l = 0, r = n - 1;
   while (l <= r)
   {
    swap(mat[i][l], mat[i][r]);
    l++;
    r--;
   }
  }
  for (int i = 0; i < n; i++)
  {
   for (int j = 0; j < n; j++)
   {
    if (j == n - 1)
    {
     cout << mat[i][j];
    }
    else
    {
     cout << mat[i][j] << " ";
    }
   }
   cout << endl;
  }
  cout << endl;
 }
 return 0;
}