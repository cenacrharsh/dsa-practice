#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Solution - 1

// # Tutorial: https://www.youtube.com/watch?v=8yf3cmMhM4g

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0)
        {
            int a_bit = i >= 0 ? a[i--] - '0' : 0;
            int b_bit = j >= 0 ? b[j--] - '0' : 0;
            int sum = a_bit + b_bit + carry;
            result.insert(result.begin(), sum % 2 + '0');
            carry = sum / 2;
        }

        if (carry)
        {
            result.insert(result.begin(), '1');
        }

        return result;
    }
};

//! Solution - 2

class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (b.size() > a.size())
        {
            swap(a, b);
        }
        while (b.size() < a.size())
        {
            b = "0" + b;
        }
        int carry = 0;
        string res = "";

        for (int i = b.size() - 1; i >= 0; --i)
        {
            if (b[i] == '1' && a[i] == '1')
            {
                if (carry == 0)
                {
                    res = "0" + res;
                }
                else
                {
                    res = "1" + res;
                }
                carry = 1;
            }
            else if (b[i] == '0' && a[i] == '0')
            {
                if (carry == 0)
                {
                    res = "0" + res;
                }
                else
                {
                    res = "1" + res;
                    carry = 0;
                }
            }
            else if ((b[i] == '0' && a[i] == '1') || (b[i] == '1' && a[i] == '0'))
            {
                if (carry == 0)
                {
                    res = "1" + res;
                }
                else
                {
                    res = "0" + res;
                    carry = 1;
                }
            }
        }

        if (carry == 1)
        {
            res = "1" + res;
        }

        return res;
    }
};
