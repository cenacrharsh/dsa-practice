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
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string ans = "";
        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            int digit1 = i >= 0 ? num1[i--] - '0' : 0;
            int digit2 = j >= 0 ? num2[j--] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            ans.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry)
        {
            ans.push_back(carry + '0'); //* ans.insert(ans.begin(), carry + '0') is a very slow operation
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};