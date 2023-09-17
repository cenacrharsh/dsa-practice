#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=8BDKB2yuGyg

//! we push first element of nums2 into stack and start iterating from 2nd element, if we find any element i.e. greater than it than we store it in map and pop if off and store the next element in stack, but if not we still store the new element in stack as we have to find the next greater element so now our curr element is the new element in num2 and this way we keep iterating and soon as we find someone greater we map it and pop it, but we do it in a while loop because the curr element might be greater than those elements that are already in stack as well, if yes we map them and pop them if not we now push this new element and move ahead as before, in the end all elements who had a next greater element have been placed in map
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> map;
        stack<int> st;
        st.push(nums2[0]);
        for (int i = 1; i < nums2.size(); i++)
        {
            if (!st.empty() && nums2[i] > st.top())
            {
                while (!st.empty() && nums2[i] > st.top())
                {
                    map[st.top()] = nums2[i];
                    st.pop();
                }
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            if (map.find(nums1[i]) != map.end())
            {
                nums1[i] = map[nums1[i]];
            }
            else
            {
                nums1[i] = -1;
            }
        }
        return nums1;
    }
};