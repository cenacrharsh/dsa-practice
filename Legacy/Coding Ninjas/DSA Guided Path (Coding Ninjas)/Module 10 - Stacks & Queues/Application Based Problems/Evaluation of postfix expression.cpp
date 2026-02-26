#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is the length of the given expression.
*/

int gcdExtended(int a, int b, int *x, int *y)
{
 // Base Case.
 if (a == 0)
 {
  *x = 0, *y = 1;
  return b;
 }

 int x1, y1;
 int gcd = gcdExtended(b % a, a, &x1, &y1);

 *x = y1 - (b / a) * x1;
 *y = x1;

 return gcd;
}

int modInverse(int b, int m)
{
 int x, y;
 // Calculate gcd.
 int g = gcdExtended(b, m, &x, &y);

 // Return -1 if b and m are not co-prime.
 if (g != 1)
 {
  return -1;
 }
 return (x % m + m) % m;
}

int evaluatePostfix(string &exp)
{
 stack<int> st;

 for (int i = 0; i < exp.length(); i++)
 {
  // If space is encountered.
  if (isspace(exp[i]))
  {
   continue;
  }

  // If the component of the string is an integer.
  else if (isdigit(exp[i]))
  {
   int num = 0;

   while (isdigit(exp[i]))
   {
    num = num * 10 + (exp[i] - '0');
    i++;
   }
   i--;
   st.push(num);
  }

  // If the component of the string is an operator.
  else
  {
   long long num1 = (long long)st.top() % 1000000007;
   st.pop();
   long long num2 = (long long)st.top() % 1000000007;
   st.pop();
   switch (exp[i])
   {
   case '+':
    st.push((num2 + num1) % 1000000007);
    break;
   case '-':
    st.push((num2 - num1 + 1000000007) % 1000000007);
    break;
   case '*':
    st.push((num2 * num1) % 1000000007);
    break;
   case '/':
    num2 = num2 % 1000000007;
    long long inv = modInverse(num1, 1000000007);
    st.push((num2 * inv) % 1000000007);
    break;
   }
  }
 }
 return st.top();
}