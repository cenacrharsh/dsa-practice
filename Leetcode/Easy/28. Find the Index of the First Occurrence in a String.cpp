#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! KMP Algorith or LPS Array

//> Optimized

/*
> Time Complexity: O(N + M) + O(N)
> Space Complexity: O(N + M)
*/

//* LPS[i] (longest prefix suffix) is the length of the longest proper prefix of the substring S[0...i] which is also a suffix of this string at that index (entire prefix != entire suffix)

class Solution
{
public:
  vector<int> computeLPS(string s)
  {
    vector<int> LPS(s.size(), 0);
    int i = 1, j = 0;

    while (i < s.size())
    {
      //* Scenario 1: When s[i] == s[j], it means that we have successfully extended an existing prefix-suffix match
      if (s[i] == s[j])
      {
        LPS[i] = j + 1;
        i++;
        j++;
      }
      //* Scenario 2: When s[i] != s[j], If s[i] ≠ s[j], we need to backtrack j without resetting it to 0 immediately. Instead, we use LPS[j-1] to find the next possible matching prefix
      else
      {
        //* Trace back j pointer till it does not match
        while (j > 0 && s[i] != s[j])
        {
          //* Why backtrack to LPS[j-1]? The value LPS[j-1] tells us the longest proper prefix that is also a suffix of the prefix ending at index j-1. If s[i] does not match s[j], then instead of rechecking from j = 0, we can check from LPS[j-1]
          j = LPS[j - 1];
        }

        //* If a match is found
        if (s[i] == s[j])
        {
          LPS[i] = j + 1;
          j++;
        }

        i++;
      }
    }
    return LPS;
  }

  int strStr(string haystack, string needle)
  {
    int n = haystack.size(), m = needle.size();
    string s = needle + '$' + haystack;

    vector<int> LPS = computeLPS(s);

    //* iterate on the combined string after the delimiter
    for (int i = m + 1; i < s.size(); i++)
    {
      if (LPS[i] == m)
      {
        return i - (2 * m); //* one m for matching index pos as we added m sized string overall first, second to go to first index as we need starting index
      }
    }
    return -1;
  }
};

//> Brute Force

/*
> Time Complexity: O(N^3)
> Space Complexity: O(N)
*/

//* LPS[i] (longest prefix suffix) is the length of the longest proper prefix of the substring S[0...i] which is also a suffix of this string at that index (entire prefix != entire suffix)

class Solution
{
public:
  vector<int> computeLPS(string s)
  {
    vector<int> LPS(s.size(), 0);

    /*
    - For each position in the string, check all possible prefix lengths that could also be suffixes.
    - Compare the prefix and suffix substrings character by character.
    - If a matching prefix-suffix is found, update the LPS value with its length.
    */

    //* iterate on the string
    for (int i = 1; i < s.size(); i++)
    {
      //* for all possible lengths
      for (int len = 1; len < i; len++)
      {
        if (s.substr(0, len) == s.substr(i - len + 1, len))
        {
          LPS[i] = len;
        }
      }
    }

    return LPS;
  }

  int strStr(string haystack, string needle)
  {
    int n = haystack.size(), m = needle.size();
    string s = needle + '$' + haystack;

    vector<int> LPS = computeLPS(s);

    for (int i = 0; i < s.size(); i++)
    {
      cout << LPS[i] << " ";
    }
    cout << endl;

    //* iterate on the combined string after the delimiter
    for (int i = m + 1; i < s.size(); i++)
    {
      if (LPS[i] == m)
      {
        cout << "Match @ Index: " << i << endl;
        return i - (2 * m); //* one m for matching index pos as we added m sized string overall first, second to go to first index as we need starting index
      }
    }
    return -1;
  }
};

//! Z Index

class Solution
{
public:
  vector<int> computeZArray(string text)
  {
    int n = text.size();
    int ans = 0;
    vector<int> zIndex(n, 0);
    for (int i = 1; i < n; i++)
    {
      //* Increment zIndex[i] till the current characters match with the prefix
      while (i + zIndex[i] < n && text[i + zIndex[i]] == text[zIndex[i]])
      {
        zIndex[i]++;
      }
    }
    return zIndex;
  }

  int strStr(string haystack, string needle)
  {
    int n = haystack.size(), m = needle.size();

    //* The delimiter ensures there are no false matches due to overlapping of the pattern with itself
    string text = needle + "$" + haystack;
    int ans = -1;
    vector<int> zArray = computeZArray(text);

    //* Iterate over the portion of the Z-array corresponding to the text. If any value in the Z-array equals the length of the pattern, it indicates a match
    for (int i = m + 1; i < text.size(); i++)
    {
      if (zArray[i] == m)
      {
        ans = i - (m + 1);
        break;
      }
    }
    return ans;
  }
};

//! Iterative

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    int n = haystack.size();
    int m = needle.size();
    int i = 0;        // to keep track of first matching index, so we can start checking again from i+1 th index in the next traversal
    int j = 0, k = 0; // to traverse the 2 strings
    while (j < n)
    {
      i = j;
      k = 0;
      if (haystack[j] == needle[k])
      {
        while (j < n && k < m && haystack[j] == needle[k])
        {
          j++;
          k++;
        }
        if (k == m)
        {
          return i;
        }
        j = i;
      }
      j++;
    }
    return -1;
  }
};