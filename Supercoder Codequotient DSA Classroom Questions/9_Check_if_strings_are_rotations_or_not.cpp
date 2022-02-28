#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int checkRotation(char str1[], char str2[])
{
 int n = strlen(str1);
 int m = strlen(str2);
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