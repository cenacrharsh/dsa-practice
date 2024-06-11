#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=nttpF8kwgd4&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=4

//! Bit Manipulation

class Solution {
public:
    bool isPowerOfTwo(int n) {
        //* binary representation of a number which is a power of 2 will only have 1 set bit, so doing N & (N-1) would result in a 0 if only 1 set bit is present in the number because N & (N - 1) unsets the rightmost set bit and everything remains as it is in this case everything was 0 already

        return (n > 0 && (n & (n - 1))  == 0 ) ? true : false;
    }
};