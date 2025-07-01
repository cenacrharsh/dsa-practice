#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Reverse (to avoid vector)

/*
> Time Complexity: O(N) + O(N) + O(N) => Overall Reverse + Traverse + Individual Words Reverse
> Space Complexity: O(1)
*/

class Solution
{
public:
  string reverseWords(string s)
  {
    reverse(s.begin(), s.end());
    int i = 0, j = 0, start = 0, end = 0;
    while (i < s.size())
    {
      //* to skip over empty spaces and reach characters
      while (i < s.size() && s[i] == ' ')
      {
        i++;
      }

      //* avoids ' ' being treated as last word
      if (i >= s.size())
      {
        continue;
      }

      //* j keeps track of the index of actual characters and one empty space after them
      start = j;
      while (i < s.size() && s[i] != ' ')
      {
        s[j] = s[i];
        i++;
        j++;
      }
      end = j - 1; //* now start -> end are the indices of first and last char of current word in new string

      //* reverse this new portion in original string
      reverse(s.begin() + start, s.begin() + end + 1); //* reverse function in not inclusive of last index so +1

      s[j] = ' ';
      j++;
    }
    return s.substr(0, j - 1);
  }
};

//! Using a Vector to store individual words

/*
> Time Complexity: O(N) + O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
  string reverseWords(string s)
  {
    string ans = "";
    vector<string> str;
    int left = s.size() - 1, right = s.size() - 1;

    while (left >= 0 && right >= 0)
    {
      while (right >= 0 && s[right] == ' ')
      {
        left--;
        right--;
      }

      while (left >= 0 && s[left] != ' ')
      {
        left--;
      }

      string temp = s.substr(left + 1, right - left);
      if (temp.size() > 0)
      {
        str.push_back(s.substr(left + 1, right - left));
      }
      right = left;
    }

    for (int i = 0; i < str.size(); i++)
    {
      ans += i == str.size() - 1 ? str[i] : str[i] + " ";
    }
    return ans;
  }
};

//! Using Prepend During String Concatenation

/*
> Time Complexity: O(N^2) => Cost of creating new string grows over time
> Space Complexity: O(1)
*/

class Solution
{
public:
  string reverseWords(string s)
  {
    string ans = "";
    int left = s.size() - 1, right = s.size() - 1;

    while (left >= 0 && right >= 0)
    {
      while (right >= 0 && s[right] == ' ')
      {
        left--;
        right--;
      }

      while (left >= 0 && s[left] != ' ')
      {
        left--;
      }

      string temp = s.substr(left + 1, right - left);
      if (temp.size() > 0)
      {
        ans += temp + " ";
      }
      right = left;
    }

    return ans.empty() ? "" : ans.substr(0, ans.size() - 1);
  }
};