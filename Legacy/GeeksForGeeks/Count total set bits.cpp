#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=nttpF8kwgd4&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=4

//! Bit Manipulation



//! Normal Loop

class Solution{
    public:
    int countSetBitsHelper(int num) {
        int count = 0;
        while(num > 1) {
            if(num % 2 == 1) {
                count++;
            }
            num = num / 2;
        }
        if(num == 1) {
            count++;
        }
        return count;
    }
    
    int countSetBits(int n)
    {
        int count = 0;
        for(int i = 1; i <= n; i++) {
            count += countSetBitsHelper(i);
        }
        return count;
    }
};