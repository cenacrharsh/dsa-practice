
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Recusion

/*
 * Complete the 'canTransformed' function below.
 * @params
 *   a,b,c,d -> integers denoting the values of a,b,c,d respectively
 * @return
 *   1 if the numbers can be transformed , else 0
 */

int canTransformed(int a, int b, int c, int d)
{
 // Write your code here
 if (a > c || b > d)
 {
  return 0;
 }

 if (a == c && b == d)
 {
  return 1;
 }

 return canTransformed(a + b, b, c, d) || canTransformed(a, a + b, c, d);

 /*
  int sum = a + b;
  if (canTransformed(sum, b, c, d))
  {
   return 1;
  }
  else
  {
   return canTransformed(a, sum, c, d);
  }
  */
}