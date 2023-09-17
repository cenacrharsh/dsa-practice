#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial : https://www.youtube.com/watch?v=A98psR_mIMQ

//! Observation

/*
Pallindrome of Len 4 :
1 - 10 01
2 - 11 11
3 - 12 21
4 - 13 31
5 - 14 41
6 - 15 51

start from 10^(len/2 - 1) if even, then for each given i add (i - 0) to it, then reverse it and add it itself

for odd, 10^(len/2) is start, then add (i - 1), reverse it but instead of simply adding ignore first digit then add

Pallindrome of Len 3 :
1 - 10 1
2 - 11 1
3 - 12 1
.
.
.
90 - 99 9 (10 + 90 - 1 = 99)
*/

class Solution
{
public:
 vector<long long> kthPalindrome(vector<int> &queries, int intLength)
 {
  int power = (intLength % 2 == 0) ? (intLength / 2 - 1) : (intLength / 2);
  int start = pow(10, power);
  vector<long long> ans;
  for (auto q : queries)
  {
   string firstHalf = to_string(start + q - 1);

   string secondHalf = firstHalf;
   reverse(secondHalf.begin(), secondHalf.end());

   string pallindrome;

   if (intLength % 2 == 0)
   {
    pallindrome = firstHalf + secondHalf;
   }
   else
   {
    pallindrome = firstHalf + secondHalf.substr(1, secondHalf.size() - 1);
   }

   //* we have to check if we have a valid pallindrome in range, for eg. if for size 2 query is 1000 th pallindrome, but no 1000th pallindrome of size 2 exists so before pushing we check if we have the valid pallindrome
   if (pallindrome.size() == intLength)
   {
    ans.push_back(stoll(pallindrome));
   }
   else
   {
    ans.push_back(-1);
   }
  }
  return ans;
 }
};