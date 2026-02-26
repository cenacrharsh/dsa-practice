#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=nttpF8kwgd4&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=4

//! Using Bit Manipulation

class Solution{   
public:
    pair<int, int> get(int a, int b){
        a = a ^ b;
        b = a ^ b; //* (a ^ b) ^ b = a
        a = a ^ b; //* (a ^ b) ^ a = b
        return {a, b};
    }
};