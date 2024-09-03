
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    int getLucky(string s, int k)
    {
        string num = "";
        for (int i = 0; i < s.size(); i++)
        {
            num += to_string((s[i] - 'a') + 1);
        }
        while (k--)
        {
            int temp = 0;
            for (int i = 0; i < num.size(); i++)
            {
                temp = temp + (num[i] - '0');
            }
            num = to_string(temp);
        }
        return stoi(num);
    }
};