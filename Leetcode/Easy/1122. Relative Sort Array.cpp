#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=4TtA2BfXvuw

//! Using Counting Sort

//! Using Hashmap

/*
> Time Complexity: O(N * Log(N)) + O(M) => put N elements into map, iterate over map of size m
> Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> freq; //* num->freq
        for(int i = 0; i < arr1.size(); i++) {
            freq[arr1[i]]++;
        }
        vector<int> ans(arr1.size(), -1);
        int k = 0;
        for(int i = 0; i < arr2.size(); i++) {
            int count = freq[arr2[i]];
            while(count--) {
                ans[k++] = arr2[i];
                freq[arr2[i]]--;
            }
        }
        for(auto& [num, fr] : freq) {
            while(fr--) {
                ans[k++] = num;
            }
        }
        return ans;
    }
};