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

int main()
{
 // Write your code here
 int t;
 cin >> t;
 while (t--)
 {
  int r1, c1;
  cin >> r1 >> c1;
  int matrix1[r1][c1];
  for (int i = 0; i < r1; i++)
  {
   for (int j = 0; j < c1; j++)
   {
    cin >> matrix1[i][j];
   }
  }

  int r2, c2;
  cin >> r2 >> c2;
  int matrix2[r2][c2];
  for (int i = 0; i < r2; i++)
  {
   for (int j = 0; j < c2; j++)
   {
    cin >> matrix2[i][j];
   }
  }

  // int i, j;

  // for (i = 0; i < r1; i++)
  // {
  //  for (j = 0; j < c1; j++)
  //  {
  //   cout << matrix1[i][j] << " ";
  //  }
  //  cout << endl;
  // }

  // for (i = 0; i < r2; i++)
  // {
  //  for (j = 0; j < c2; j++)
  //  {
  //   cout << matrix2[i][j] << " ";
  //  }
  //  cout << endl;
  // }

  int ans[r1][c2] = {0};
  // for (int i = 0; i < r1; i++)
  // {
  //  for (int j = 0; j < c2; j++)
  //  {
  //   ans[i][j] = 0;
  //  }
  // }
  // for (int i = 0; i < r1; i++)
  // {
  //  for (int j = 0; j < c2; j++)
  //  {
  //   cout << ans[i][j] << " ";
  //  }
  //  cout << endl;
  // }
  int i, j, k;
  for (i = 0; i < r1; i++)
  {
   for (j = 0; j < c2; j++)
   {
    ans[i][j] = 0;
    for (k = 0; k < c1; k++)
    {
     ans[i][j] += matrix1[i][k] * matrix2[k][j];
    }
   }
  }

  for (i = 0; i < r1; i++)
  {
   for (j = 0; j < c2; j++)
   {
    cout << ans[i][j] << " ";
   }
   cout << endl;
  }
 }
 // Return 0 to indicate normal termination
 return 0;
}
