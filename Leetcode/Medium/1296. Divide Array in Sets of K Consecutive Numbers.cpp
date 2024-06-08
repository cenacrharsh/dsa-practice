#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=CnMwFyoD0Bk

/*
> Time Complexity: O(N*Log(N)) + O(N) => Number of Distince Elements In One Group + Number of Elements In One Group
> Space Complexity: O(N)
*/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        //* in each group elements have to be consecutive, eg. if group starts with i then it has to contain (i + 1) and (i + 2) and so on
        if(nums.size() % k != 0) {
            return false;
        }
        map<int, int> mp; //* char-> freq in sorted order as each group has to start with smallest avaiable number
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(auto [num, freq] : mp) {
            //* num has to be first element in freq number of groups
            while(freq--) {
                for(int i = num; i < num + k; i++) {
                    if(mp[i] == 0) {
                        return false;
                    }
                    mp[i]--;
                }
            }
        } 
        return true;
    }
};