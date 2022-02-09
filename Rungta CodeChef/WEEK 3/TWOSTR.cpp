/*
Chef and the Wildcard Matching Problem Code: TWOSTR

Chef wants to implement wildcard pattern matching supporting only the wildcard '?'. The wildcard character '?' can be substituted by any single lower case English letter for matching. He has two strings X and Y of equal length, made up of lower case letters and the character '?'. He wants to know whether the strings X and Y can be matched or not.

Input
The first line of input contain an integer T denoting the number of test cases. Each test case consists of two lines, the first line contains the string X and the second contains the string Y.

Output
For each test case, output a single line with the word Yes if the strings can be matched, otherwise output No.

Constraints
1 ≤ T ≤ 50
Both X and Y have equal length and the length is between 1 and 10.
Both X and Y consist of lower case letters and the character '?'.
Sample Input 1 
2
s?or?
sco??
stor?
sco??
Sample Output 1 
Yes
No
Explanation
First Example: There are several ways the two strings can be matched, one of those is "score".

Second Example: There is no way to match the strings.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  string x, y;
  cin >> x;
  cin >> y;

  bool ans = true;

  for (int i = 0; i < x.length(); i++)
  {
   if (x[i] != '?' && y[i] != '?')
   {
    if (x[i] != y[i])
    {
     ans = false;
    }
   }
  }

  cout << (ans ? "Yes" : "No") << endl;
 }
 return 0;
}