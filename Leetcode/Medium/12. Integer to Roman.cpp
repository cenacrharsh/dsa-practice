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
    string intToRoman(int num)
    {
        string roman = "";
        vector<pair<int, string>> intToRomanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        for (int i = 0; i < intToRomanMap.size(); i++)
        {
            while (num >= intToRomanMap[i].first)
            {
                roman += intToRomanMap[i].second;
                num -= intToRomanMap[i].first;
            }
        }

        return roman;
    }
};