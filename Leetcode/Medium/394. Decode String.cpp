#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=0iQqj5egK9k

//! Using while loop
class Solution
{
public:
 string decodeString(string s)
 {
  // we can encounter either a digit, [, ], or character
  stack<int> countStack;
  stack<string> wordStack;
  string returnedString = "";
  int index = 0;
  while (index < s.size())
  {
   if (isdigit(s[index]))
   {
    int num = 0;
    while (isdigit(s[index]))
    {
     num = num * 10 + (s[index] - '0');
     index++;
    }
    countStack.push(num);
   }
   else if (isalpha(s[index]))
   {
    returnedString += s[index];
    index++;
   }
   else if (s[index] == '[')
   {
    wordStack.push(returnedString);
    returnedString = "";
    index++;
   }
   else if (s[index] == ']')
   {
    string poppedWord = wordStack.top();
    wordStack.pop();
    int poppedCount = countStack.top();
    countStack.pop();
    //* "3[a2[c]]" => at first ] we have c as running string and we get 2 and a from stack, we want to add curr runnig string 2 times to word we got from stack i.e a, then it becomes acc, then we update curr running word to acc
    for (int i = 0; i < poppedCount; i++)
    {
     poppedWord += returnedString;
    }
    returnedString = poppedWord;
    index++;
   }
  }
  return returnedString;
 }
};

//! Using for loop
class Solution
{
public:
 string decodeString(string s)
 {
  // we can encounter either a digit, [, ], or character
  stack<int> countStack;
  stack<string> wordStack;
  string returnedString = "";
  int num = 0;
  for (int index = 0; index < s.size(); index++)
  {
   if (isdigit(s[index]))
   {
    num = num * 10 + (s[index] - '0');
   }
   else if (isalpha(s[index]))
   {
    returnedString += s[index];
   }
   else if (s[index] == '[')
   {
    countStack.push(num);
    wordStack.push(returnedString);
    num = 0;
    returnedString = "";
   }
   else if (s[index] == ']')
   {
    string poppedWord = wordStack.top();
    wordStack.pop();
    int poppedCount = countStack.top();
    countStack.pop();
    for (int i = 0; i < poppedCount; i++)
    {
     poppedWord += returnedString;
    }
    returnedString = poppedWord;
   }
  }
  return returnedString;
 }
};