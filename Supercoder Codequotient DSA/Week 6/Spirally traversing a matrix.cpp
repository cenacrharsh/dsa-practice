#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#define ROWS 50
#define COLS 50

void printSpiral(int a[ROWS][COLS], int r, int c)
{
 // Write your code here
 int top = 0, down = r - 1, left = 0, right = c - 1;
 int dir = 0;
 while (top <= down && left <= right)
 {
  if (dir == 0)
  {
   for (int i = top; i <= right; i++)
   {
    cout << a[top][i] << endl;
   }
   top++;
   dir = 1;
  }
  else if (dir == 1)
  {
   for (int i = top; i <= down; i++)
   {
    cout << a[i][right] << endl;
   }
   right--;
   dir = 2;
  }
  else if (dir == 2)
  {
   for (int i = right; i >= left; i--)
   {
    cout << a[down][i] << endl;
   }
   down--;
   dir = 3;
  }
  else if (dir == 3)
  {
   for (int i = down; i >= top; i--)
   {
    cout << a[i][left] << endl;
   }
   left++;
   dir = 0;
  }
  // dir = (dir+1)%4;
 }
}

int main()
{
 int r, c;
 cin >> r >> c;
 int a[ROWS][COLS], i, j;
 for (i = 0; i < r; i++)
  for (j = 0; j < c; j++)
   cin >> a[i][j];
 printSpiral(a, r, c);
 return 0;
}