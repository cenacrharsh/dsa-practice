#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=UyXy1mVB1iU

class Solution
{
public:
 string minimizeResult(string expr)
 {
  // First find the index of '+ in expresseion. let it be idx.
  int idx;
  int n = expr.size();
  for (int i = 0; i < n; i++)
   if (expr[i] == '+')
   {
    idx = i;
    break;
   }

  // Now find two numbers which are on left and right side of '+' sign in expression
  string num1 = expr.substr(0, idx);
  string num2 = expr.substr(idx + 1, n - idx - 1);

  // b1 and b2 are for brackets . b1=left bracket, b2=right bracket
  int b1 = 0, b2 = 0;
  int min = INT_MAX;
  string ans;

  // p1 and p2 are product number outside the brackets i.e our expresion is p1(sum)p2
  int p1, p2;

  // Find all possible conditions, iterate left bracket over num1 and right bracket over num2
  for (int b1 = 0; b1 < num1.size(); b1++)
  {
   for (int b2 = 0; b2 < num2.size(); b2++)
   {
    // s1 and s2 are strings which are outside the left parenthesis and right parenthesis respectively
    string s1 = num1.substr(0, b1);
    string s2 = num2.substr(b2 + 1, b2 - num2.size() - 1);

    // if any of the string is empty then its int value should be 1 else its same as string.
    if (s1.empty())
     p1 = 1;
    else
     p1 = stoi(num1.substr(0, b1));
    if (s2.empty())
     p2 = 1;
    else
     p2 = stoi(num2.substr(b2 + 1, b2 - num2.size() - 1));

    // sum stores the numerical value of the sum between the parenthesis
    int sum = stoi(num1.substr(b1, num1.size())) + stoi(num2.substr(0, b2 + 1));
    // eval stores the numerical value of whole expression
    int eval = p1 * sum * p2;

    // if velue of expression is less then minimum, then make ans string = s1(sum) s1
    if (eval < min)
    {

     min = eval;
     ans = s1 + "(" + num1.substr(b1, num1.size()) + "+" + num2.substr(0, b2 + 1) + ")" + s2;
    }
   }
  }
  return ans;
  // return final string
 }
};

class Solution
{
public:
 string minimizeResult(string expression)
 {
  int smallestVal = INT_MAX;
  int leftIndex = -1;
  int rightIndex = -1;
  int plusIndex = -1;
  int length = 0;

  for (int i = 0; i < expression.size(); i++)
  {
   if (expression[i] == '+')
   {
    plusIndex = i;
    break;
   }
  }

  for (int i = 0; i < plusIndex; i++)
  {
   int k = 1;
   for (int j = plusIndex + 1; j < expression.size(); j++)
   {
    string n1Str = expression.substr(0, i);
    int n1 = 1;
    if (n1Str.size() > 0)
    {
     n1 = stoi(n1Str);
    }

    string n2Str = expression.substr(i, plusIndex);
    int n2 = stoi(n2Str);

    string n3Str = expression.substr(plusIndex + 1, k); // j+1
    int n3 = stoi(n3Str);
    k++;

    string n4Str = expression.substr(j + 1);
    int n4 = 1;
    if (n4Str.size() > 0)
    {
     n4 = stoi(n4Str);
    }

    int currVal = n1 * (n2 + n3) * n4;
    if (currVal < smallestVal)
    {
     smallestVal = currVal;
     leftIndex = i;
     rightIndex = j + 1;
     length = plusIndex + k - i;
    }
   }
  }
  string ans = "";
  ans += expression.substr(0, leftIndex);
  ans += "(";
  ans += expression.substr(leftIndex, length);
  ans += ")";
  ans += expression.substr(rightIndex);

  return ans;
 }
};