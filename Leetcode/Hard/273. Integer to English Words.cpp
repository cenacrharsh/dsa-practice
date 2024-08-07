#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=SCtIlKd3mDM

//! Using Hashmap

class Solution
{
public:
    unordered_map<int, string> ones_map = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"}};

    unordered_map<int, string> tens_map = {
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"}};

    string getString(int n)
    {
        vector<string> res;
        int hundreds = n / 100;
        if (hundreds)
        {
            res.push_back(ones_map[hundreds] + " Hundred");
        }

        int last2digits = n % 100;

        if (last2digits >= 20)
        {
            int tens = last2digits / 10;
            int ones = last2digits % 10;

            res.push_back(tens_map[tens * 10]);
            if (ones != 0)
            {
                res.push_back(ones_map[ones]);
            }
        }
        else if (last2digits != 0)
        {
            res.push_back(ones_map[last2digits]);
        }

        string str = "";
        for (int i = 0; i < res.size(); i++)
        {
            if (i != res.size() - 1)
            {
                str = str + res[i] + " ";
            }
            else
            {
                str = str + res[i];
            }
        }
        return str;
    }

    string numberToWords(int num)
    {
        if (num == 0)
        {
            return "Zero";
        }

        int i = 0;
        vector<string> res;
        vector<string> postfix = {"", " Thousand", " Million", " Billion"};
        while (num != 0)
        {
            int digits = num % 1000;
            string str = getString(digits);
            if (str != "")
            {
                res.push_back(str + postfix[i]);
            }

            num = num / 1000;
            i++;
        }

        reverse(res.begin(), res.end());
        string ans = "";
        for (int i = 0; i < res.size(); i++)
        {
            if (i != res.size() - 1)
            {
                ans = ans + res[i] + " ";
            }
            else
            {
                ans = ans + res[i];
            }
        }
        return ans;
    }
};