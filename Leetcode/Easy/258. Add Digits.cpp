#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Without Loop

/*
dr(n) = 0, if n = 0
dr(n) = 9, if n = 9k
dr(n) = n mod 9, if n != 9k
*/

class Solution
{
public:
    int addDigits(int num)
    {
        if (num == 0)
            return 0;
        if (num % 9 == 0)
            return 9;
        return num % 9;
    }
};

// or

    class Solution
{
public:
    int addDigits(int num)
    {
        return num == 0 ? 0 : 1 + (num - 1) % 9;
    }
};

//! Using Loop
class Solution
{
public:
    int addDigits(int num)
    {
        while (!(num >= 0 && num <= 9))
        {
            int temp = num;
            int sum = 0;
            while (temp > 0)
            {
                int lastDigit = temp % 10;
                sum += lastDigit;
                temp = temp / 10;
            }
            num = sum;
        }
        return num;
    }
};