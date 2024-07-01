#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0;
        int count = 0;
        while(i < arr.size()) {
            if(arr[i] % 2 == 1) {
                count++;
                if(count == 3) {
                    return true;
                }
            } else {
                count = 0;
            }
            i++;
        }
        return false;
    }
};