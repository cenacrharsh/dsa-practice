#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=s8ZaYDuYqmo

//! 2 Pointers

class Solution {
public:
    int appendCharacters(string s, string t) {
        int left = 0, right = 0;
        while(left < s.size() && right < t.size()) {
            if(s[left] == t[right]) {
                left++;
                right++;
            } else {
                left++;
            }
        }
        return t.size() - right;
    }
};