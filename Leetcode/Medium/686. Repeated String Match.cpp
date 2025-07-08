#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Rabin Karp

/*
> Time Complexity: O(M) + O(N - M) ~ O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
  bool rabinKarpStringSearch(string text, string pattern)
  {
    cout << text << " " << pattern << endl;
    int n = text.size(), m = pattern.size();
    int p = 7, mod = 101, hashText = 0, hashPattern = 0;
    int powerRight = 1, powerLeft = 1;
    for (int i = 0; i < m; i++)
    {
      hashPattern = (hashPattern + (pattern[i] - 'a' + 1) * powerRight) % mod; //* we want to treat a as 1, b as 2...
      hashText = (hashText + (text[i] - 'a' + 1) * powerRight) % mod;
      powerRight = (powerRight * p) % mod;
    }

    for (int i = 0; i <= n - m; i++)
    {
      //* to avoid collisions we use substr
      if (hashPattern == hashText && text.substr(i, m) == pattern)
      {
        return true;
      }

      //* move ahead in text for search, we have to remove left most character
      //* during substraction always do + mod to avoid negative values
      hashText = (hashText - (text[i] - 'a' + 1) * powerLeft % mod + mod) % mod;

      //* add next character
      hashText = ((hashText + (text[i + m] - 'a' + 1) * powerRight) % mod) % mod;

      hashPattern = (hashPattern * p) % mod;

      powerLeft = (powerLeft * p) % mod;
      powerRight = (powerRight * p) % mod;
    }
    return false;
  }

  int repeatedStringMatch(string a, string b)
  {
    int n = a.size(), m = b.size();

    int ans = 1;
    string temp = a;
    while (a.size() < b.size())
    {
      a += temp;
      ans++;
    }

    if (rabinKarpStringSearch(a, b))
    {
      return ans;
    }

    a += temp;
    if (rabinKarpStringSearch(a, b))
    {
      return ans + 1;
    }
    return -1;
  }
};

//! Brute Force

/*
> Time Complexity: O(M * N)
> Space Complexity: O(1)
*/

class Solution
{
public:
  bool stringSearch(string str, string pattern)
  {
    int m = str.size(), n = pattern.size();
    for (int i = 0; i <= m - n; i++)
    {
      bool flag = true;
      for (int j = 0; j < n; j++)
      {
        if (pattern[j] != str[i + j])
        {
          flag = false;
          break;
        }
      }
      if (flag)
        return true;
    }
    return false;
  }

  int repeatedStringMatch(string a, string b)
  {
    int n = a.size(), m = b.size();

    int ans = 1;
    string temp = a;
    while (a.size() < b.size())
    {
      a += temp;
      ans++;
    }

    if (stringSearch(a, b))
    {
      return ans;
    }

    a += temp;
    if (stringSearch(a, b))
    {
      return ans + 1;
    }
    return -1;
  }
};