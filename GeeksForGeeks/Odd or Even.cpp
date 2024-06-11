#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution{   
public:
    string oddEven(int N){
        //* since last digit of a odd number is always 1, upon n & 1 it becomes 1 if it was odd else it becomes 0
        
        return (N & 1 == 1) ? "odd" : "even";
    }
};

