#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

void sorting012Array(int a[], int n)
{
 // Write your code here
 int l = 0, mid = 0, h = n - 1;

 while (mid <= h)
 {
  if (a[mid] == 0)
  {
   swap(a[l++], a[mid++]);
  }
  else if (a[mid] == 1)
  {
   mid++;
  }
  else if (a[mid] == 2)
  {
   swap(a[l], a[h--]);
  }
 }
}