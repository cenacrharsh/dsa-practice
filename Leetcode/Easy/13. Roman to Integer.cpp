#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int n = s.size();
        int sum = 0;
        int num = 0;

        for (int i = 0; i < n;)
        {
            //* if current element is bigger than next element
            if (i == (n - 1) || (roman[s[i]] >= roman[s[i + 1]]))
            {
                num = roman[s[i]];
                i++;
            }
            //* if current element is smaller than next element, eg: IV, XL, CD
            else
            {
                num = roman[s[i + 1]] - roman[s[i]];
                i = i + 2;
            }
            sum += num;
        }

        return sum;
    }
};