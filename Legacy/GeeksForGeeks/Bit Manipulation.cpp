#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=nttpF8kwgd4&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=4


class Solution {
public:
    void bitManipulation(int num, int i) {
        //* get ith bit
        cout << (((num >> (i - 1)) & 1) == 1 ? '1' : '0') << " ";
        
        //* set the ith bit, at the ith bit we need a 1 and upon doing OR everything else remains same but if kth bit is 1 or 0 we would get a 1 
        cout << (num | (1 << (i - 1))) << " ";
        
        //* clear the ith bit, at the ith bit we need a 0 but in all other places we need a 1, upon doing & 0 would remain 0 1 would remain 1 but since we have 0 at kth bit we would a 0
        cout << (num & (~(1 << (i - 1))));
    }
};

