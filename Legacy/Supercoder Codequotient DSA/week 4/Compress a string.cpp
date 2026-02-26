#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

string compressString(string str)
{
 string res;
 int n = str.size();
 int i, j = 0;
 for (int i = 0; i < n; i++)
 {
  //> maintain count of first occurence of character as 1 and insert it into resultant string
  int count = 1;
  res += str[i];

  while (i + 1 < n && str[i] == str[i + 1])
  {
   count++;
   i++;
  }

  if (count > 1)
  {
   string countString = to_string(count);
   res += countString;
  }
 }
 return res;
}

int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  string str;
  cin >> str;
  string compressed = compressString(str);
  cout << compressed << endl;
 }
 return 0;
}

void compressString(char str[])
{
 int n = strlen(str);
 char res[n + 1];
 int i, j = 0;
 for (int i = 0; i < n; i++)
 {
  //> maintain count of first occurence of character as 1 and insert it into resultant string
  int count = 1;
  res[j++] = str[i];

  while (i + 1 < n && str[i] == str[i + 1])
  {
   count++;
   i++;
  }

  if (count > 1)
  {
   char temp[50];
   // temp = toString(count);
   for (int k = 0; k < strlen(temp); k++)
   {
    res[j++] = temp[k];
   }
  }
 }
 res[j] = '\0';
}

void compressStrin(char str[])
{
 int n = strlen(str);
 int i, j = 0;
 for (int i = 0; i < n; i++)
 {
  int count = 1;
  str[j++] = str[i];

  while (i + 1 < n && str[i] == str[i + 1])
  {
   count++;
   i++;
  }

  if (count > 1)
  {
   char temp[50];
   // temp = toString(count);
   for (int k = 0; k < strlen(temp); k++)
   {
    str[j++] = temp[k];
   }
  }
 }
 str[j] = '\0';
}

int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  string str;
  cin >> str;
  // compressString(str);
 }
 return 0;
}
