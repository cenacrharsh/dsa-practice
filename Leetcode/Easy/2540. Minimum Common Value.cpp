#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using 2 Pointers

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                return nums1[i];
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
        }
        return -1;
    }
};

//! Using Unordered Map

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> freq;
        for (int num : nums1)
        {
            freq[num]++;
        }
        for (int num : nums2)
        {
            if (freq.find(num) != freq.end())
            {
                return num;
            }
        }
        return -1;
    }
};