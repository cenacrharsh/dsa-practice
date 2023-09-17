#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <unordered_map>
using namespace std;

//! String

void expandString(string str, string &res)
{
 // Write your code here
 for (int i = 0; i < str.size(); i++)
 {
  char ch = str[i];
  int count = 1;
  char temp[50];
  int k = 0;
  while (i + 1 < str.size() && str[i + 1] >= '0' && str[i + 1] <= '9')
  {
   temp[k] = str[i + 1];
   k++;
   i++;
  }
  temp[k] = '\0';
  if (strlen(temp) > 0)
  {
   count = atoi(temp);
  }
  while (count--)
  {
   res += ch;
  }
 }
}

//! Char Array

#include <bits/stdc++.h>
using namespace std;
void expandString(char *str, char *res)
{
 int n = strlen(str);
 int i = 0, j = 0;
 for (i = 0; i < n; i++)
 {
  char c = str[i];
  int count = 1;
  char temp[50];
  int k = 0;
  while (i + 1 < n && str[i + 1] >= '0' && str[i + 1] <= '9')
  {
   temp[k] = str[i + 1];
   k++;
   i++;
  }
  temp[k] = '\0';
  if (strlen(temp) > 0)
   count = atoi(temp);
  while (count--)
  {
   res[j] = c;
   j++;
  }
 }
 res[j] = '\0';
}

int main()
{
 char str[] = "a2b3c2de";
 char res[100000];
 expandString(str, res);
 cout << res;
 return 0;
}
