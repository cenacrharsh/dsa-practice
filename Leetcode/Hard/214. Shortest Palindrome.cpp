#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(2N) + O(2N) + O(2N) => O(N)
> Space Complexity: O(N)
*/

//* Calcuate LPS to figure out how much of the string is already a pallindrome, then what is left is what we need to add

//* The solution leverages the Longest Prefix Suffix (LPS) array, which captures the length of the longest prefix of a string that is also a suffix. By combining the string and its reverse with a delimiter, the LPS array helps identify the largest palindromic prefix in the string. This ensures the minimum number of characters are added to the front to complete the palindrome

class Solution
{
public:
  vector<int> computeLPS(string str)
  {
    vector<int> LPS(str.size(), 0);
    int i = 1, j = 0;
    while (i < str.size())
    {
      if (str[i] == str[j])
      {
        LPS[i] = j + 1;
        i++;
        j++;
      }
      else
      {
        while (j > 0 && str[i] != str[j])
        {
          j = LPS[j - 1];
        }

        if (str[i] == str[j])
        {
          LPS[i] = j + 1;
          j++;
        }

        i++;
      }
    }
    return LPS;
  }

  string shortestPalindrome(string s)
  {
    string reverseOfS = s;
    reverse(reverseOfS.begin(), reverseOfS.end());
    string str = s + '$' + reverseOfS; //* TC: O(2N)

    vector<int> LPS = computeLPS(str); //* TC: O(2N)

    int numOfCharToBeAdded = s.size() - LPS.back();

    return reverseOfS.substr(0, numOfCharToBeAdded) + s; //* TC: O(2N)
  }
};