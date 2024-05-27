#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: 1608. Special Array With X Elements Greater Than or Equal X

//! Double Binary Search

/*
> Time Complexity: O(N * Log(N) + Log^2(N)) -> double BS
> Space Complexity: O(Log(N))
*/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        //* we know we can't have ans > N because we need the num of >= elements in array to be = ans, so ans has to lie in b/w 1->N
        //* as we traverse from 1 to N, the number of elements >= x in the array decreases linearly hence we can apply a binary search here as well
        //* so we'll do binary search on 1->N and for each x we'll don a binary search on sorted nums to find out num elements >= x for which we'll use lower_bound(x) (smallest number >= x) which would indicate all elements from index i till end are >= our x, if num is lesser than x we move left to inc num value, and if num if greater than we move right to decrease num value until we find num == x

        sort(nums.begin(), nums.end());
        int left = 1, right = nums.size(), ans = -1;

        //* BS on 1->N, elements are in increasing order
        while(left <= right) {
            int mid = (left + right) / 2;

            //* BS on freq of elements >= [1->N], elements are in decreasing order
            //* find out how many elements in nums are >= nums[mid]
            int count = nums.end() - lower_bound(nums.begin(), nums.end(), mid);

            if(count == mid) {
                ans = mid;
                break;
            } else if(count > mid) {
                left = mid + 1; //* if number increases count(elements >= number) decreases
            } else if(count < mid) {
                right = mid - 1; //* if number decreases count(elements >= number) increases
            }
        }
        return ans;
    }
};

//! Simple Sorting

/*
> Time Complexity: O(N * Log(N) + N) -> Sorting + Traversal
> Space Complexity: O(Log(N)) -> Space required for sorting
*/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        //* we initially keep count as 0 and if nums[i] >= it then we increment count 
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] >= count) {
                count++;
                //* if there are more elements >= count in nums
                if(count > nums[i]) {
                    return -1;
                }
            } else {
                return count;
            }
        }
        return nums.size();
    }
};