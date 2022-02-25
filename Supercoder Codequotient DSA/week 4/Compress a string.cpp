#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

string compressString(string str)
{
 // Write your code here
 int n = str.length;
 string res;
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
   string s = to_string(count);
   res += s;
  }
 }
 res += "\0";
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