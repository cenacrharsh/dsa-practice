#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimal (Sorting + 3 Pointers)

/*
> Time Complexity: O(N * Log(N)) + O(N * N) => Sort + For * While
> Space Complexity: O(No. of unique triplets)
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        //* in the optimal solution we figured out the indices then sorted it before storing, we needed another data structure in the end just to filter out the duplicates
        //* we'll sort the entire array and try to find unique triples directly using 3 pointers

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};

//! Better (TLE)

/*
> Time Complexity: O(N^2 * Log M) => M is variable because size of set keeps changing
> Space Complexity: O(N) + O(No. of unique triplets) * 2
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        //* arr[k] = -(arr[i] + arr[j])
        set<vector<int>> st; //* to make sure triplets are unique

        //* we'll run 2 for loops for 2 elements and try to find the third one in the hashmap
        for (int i = 0; i < nums.size(); i++)
        {
            set<int> hashSet;
            for (int j = i + 1; j < nums.size(); j++)
            {
                int targetLeft = -(nums[i] + nums[j]);
                if (hashSet.find(targetLeft) != hashSet.end())
                {
                    vector<int> temp = {nums[i], nums[j], targetLeft};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//! Brute Force (3 Loops)

/*
> Time Complexity: O(N^3)
> Space Complexity: O(1)
*/