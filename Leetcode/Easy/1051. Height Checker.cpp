#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Counting Sort

/*
> Time Complexity: O(N) + O(K) => Size of Array + Size of Resultant Array
> Space Complexity: O(N) + O(K)
*/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        //* numbers represent the index and thier value == freq of that element, eg. if 2 occures 5 times then in the resultant array arr[2] = 5, and when we traverse in this array from left->right we access the elements in sorted order
        //* useful when largest number in array is not that big
        //* TC: O(N + K) where N is the total size of input array & K is the max element in input array depending on which size of resultant array = K, SC: O(N + K)

        vector<int> count(101, 0);
        for(int i = 0; i < heights.size(); i++) {
            count[heights[i]]++;
        }

        int ans = 0;
        int k = 0;
        for(int i = 0; i < heights.size(); i++) {
            //* find first non-zero index in count array
            while(count[k] == 0) {
                k++;
            }

            if(heights[i] != k) {
                ans++;
            }
            count[k]--; //* in case of match or mismatch we have to decrease the freq in count array because we have to match index by index so if index moves ahead we have to decrease count as well to move in parallel
        }
        return ans;
    }
};

//! Sorting

/*
> Time Complexity: O(N * Log(N)) + O(N) => Sorting + Iterating
> Space Complexity: O(Log(N)) + O(N) => Sorting + Duplicate Array
*/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp = heights;
        sort(temp.begin(), temp.end());
        int count = 0;
        for(int i = 0 ; i < heights.size() ; i++)
        {
            if(heights[i] != temp[i])
            {
                count++;
            }
        }
        return count;
    }
};