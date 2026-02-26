#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=nttpF8kwgd4&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=4

//! Left Shift Operator

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        //* counting is done from the right -> LSB
        //* (1 << k) would give 1 at the kth index and 0's everywhere, when this number is & with n, i.e n & (1 << k) we would get 0's everywhere except kth index, kth index would be 0 if n had 0 at kth index or 1 if n had 1 at kth index, so overall if n & (1 << k) != 0 it means kth bit was set else not set
        return (n & (1 << k)) != 0 ? true : false;
    }
};

//! Right Shift Operator

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        //* counting is done from the right -> LSB
        //* (n >> k) would place the kth bit at the rightmost position and upon (n >> k) & 1 which has 1 at the rightmost bit and 0 everywhere else, we would get 1 if the kth bit was set else we would get 0
        return ((n >> k) & 1) == 1 ? true : false;
    }
};