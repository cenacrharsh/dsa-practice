#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=PjKjbpI2Z3s

//! Using Lambda Func in Sort Func

//> Lamda Func: [&] (parameters) { return Expresssion }
//> The capture clause [&] captures all external variables used inside the lambda function by reference. In this case, it captures freq, allowing the lambda to access the unordered_map<int, int> freq defined outside the lambda.

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto i : nums)
        {
            freq[i]++;
        }
        
        //* using lambda func
        sort(nums.begin(), nums.end(), [&] (int a ,int b) {
            return ( freq[a] != freq[b] ? freq[a] < freq[b] : a > b ) ;
        });

        /*
        The body of the lambda contains a conditional (ternary) operator:
            freq[a] != freq[b]: This condition checks if the frequency of a is different from the frequency of b.
            If true, it returns freq[a] < freq[b], meaning elements with lower frequencies will come first.
            If false (i.e., a and b have the same frequency), it evaluates a > b, meaning for elements with the same frequency, the element with the larger value will come first.
        */
        
        return nums;
    }
};

// # Tutorial: https://www.youtube.com/watch?v=S6UvwcpVnxc

//! Using Hashmap & Vector of Vector

class Solution
{
public:
    static bool comparator(vector<int> a, vector<int> b)
    {
        if (a[0] != b[0])
        {
            return a[0] < b[0]; //* ele with less freq before, i.e. asc order
        }
        else
        {
            return a[1] > b[1]; //* if freq same then ele with larger value before, i.e. des order
        }
    }
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (auto i : nums)
        {
            freq[i]++;
        }
        vector<vector<int>> v;
        for (auto i : freq)
        {
            v.push_back({i.second, i.first}); //* freq -> element
        }
        //* sort
        sort(v.begin(), v.end(), comparator);
        vector<int> ans;
        for (auto i : v)
        {
            int count = i[0];
            while (count--)
            {
                ans.push_back(i[1]);
            }
        }
        return ans;
    }
};