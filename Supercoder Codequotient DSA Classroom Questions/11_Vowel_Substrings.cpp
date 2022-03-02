#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int countVowelSubstring(string str)
{
 int count = 0;
 int n = str.length();

 for (int i = 0; i < n; i++)
 {
  if (str[i] == 'a' ||
      str[i] == 'e' ||
      str[i] == 'i' ||
      str[i] == 'o' ||
      str[i] == 'u' ||
      str[i] == 'A' ||
      str[i] == 'E' ||
      str[i] == 'I' ||
      str[i] == 'O' ||
      str[i] == 'U')
  {
   //* everytime before updating count, doing the modulo operation to avoid integer overflow
   count = (count + (n - i) % 10007) % 10007;
  }
 }
 return count;
}