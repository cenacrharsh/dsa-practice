#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

//! Approach 1

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

// return 1 for YES and 0 for NO.
int isRotation(string str1, string str2)
{
 // Write your code here
 int n = str1.size();
 int m = str2.size();
 if (n != m)
 {
  return 0;
 }

 string newString = str1 + str1;
 int found = newString.find(str2);
 if (found != string::npos)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}

//! Approach 2

/*
> Time Complexity: O(n2)
> Space Complexity: O(1)
*/

// return 1 for YES and 0 for NO.
int isRotation(string str1, string str2)
{
 // Write your code here
 int n = str1.size();
 int m = str2.size();

 if (n != m)
 {
  return 0;
 }

 for (int i = 0; i < n; i++)
 {
  char temp = str1[0];
  for (int j = 0; j < n - 1; j++)
  {
   str1[j] = str1[j + 1];
  }
  str1[n - 1] = temp;
  if (str1 == str2)
  {
   return true;
  }
 }
 return false;
}
