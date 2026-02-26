#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using string

void revWordsString(string str)
{
 int l, r;
 int n = str.size();
 for (int i = 0; i < n; i++)
 {
  if (str[i] != ' ')
  {
   l = i;
   while (i < n && str[i] != ' ')
   {
    i++;
   }
   r = i;
   //* reverse the string from [l,r)
   reverse(str.begin() + l, str.begin() + r);

   // cout << "left: " << l << " right: " << r << endl;
   // if (r < n)
   // {
   //  reverse(str.begin() + l, str.begin() + r);
   // }
   // else
   // {
   //  reverse(str.begin() + l, str.end());
   // }
  }
 }
 cout << str << endl;
}

//! Using Array of Charactres/String Literal

void reverseWord(char str[], int l, int r)
{
 while (l < r)
 {
  char temp = str[l];
  str[l] = str[r];
  str[r] = temp;

  l++;
  r--;
 }
}

void revWordsString(char str[], int n)
{
 int l, r;
 for (int i = 0; i < n; i++)
 {
  if (str[i] != ' ')
  {
   l = i;
   while (i < n && str[i] != ' ')
    i++;
   r = i - 1;
   reverseWord(str, l, r);
  }
 }
}

int main()
{
 char str[] = "Code Quotient Loves Code";
 int n = strlen(str);

 // revWordsString(str, n);
 // printf("%s", str);

 revWordsString(str);
 // cout << str << endl;

 return 0;
}
