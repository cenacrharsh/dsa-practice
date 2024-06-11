#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=4TtA2BfXvuw

//! Using Counting Sort

/*
> Time Complexity: O(N) + O(M) + O(K)
> Space Complexity: O(K)
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxElement = *max_element(arr1.begin(), arr1.end());
        vector<int> count(maxElement + 1, 0);
        for(int num : arr1) {
            count[num]++;
        }

        vector<int> ans;
        for(int num : arr2) {
            while(count[num]--) {
                ans.push_back(num);
            }
        }
        
        for(int i = 0; i <= maxElement; i++) {
            //* in boolean context all non-zero numbers including negative numbers like -1 are considered true as well, only 0 is considered false
            while(count[i] > 0 && count[i]--) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

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