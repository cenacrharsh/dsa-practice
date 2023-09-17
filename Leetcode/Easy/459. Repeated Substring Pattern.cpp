#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=bClIZj66dVE

/*
> Time Complexity: O(N^2)
> Space Complexity: O(N)
*/

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        //* loop till half the string, and everytime if it's possible to add that substring some number of times and get the original string then we do that and then compare, for eg. a substring of size 3 can't be added to get a string of size 8 but a substring of size 2 can be
        int len = s.size();
        for (int i = len / 2; i >= 1; i--)
        {
            if (len % i == 0)
            {
                //* it shows it's possible to add substring of size i numRepeat times to get a string of size len
                int numRepeat = len / i;
                string tempString = "";
                string subString = s.substr(0, i);
                for (int i = 0; i < numRepeat; i++)
                {
                    tempString += subString;
                }
                cout << tempString << endl;
                if (tempString == s)
                {
                    return true;
                }
            }
        }
        return false;
    }
};