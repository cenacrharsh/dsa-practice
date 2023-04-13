#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using 2 pointers (Modifies input array)
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int i = 0, j = 0;
        for (int num : pushed)
        {
            pushed[i] = num; // similar to pushing in stack
            i++;
            while (i > 0 && pushed[i - 1] == popped[j])
            {
                i--; // similar to popping in stack
                j++;
            }
        }
        // if we reach first index again then it's a valid sequence
        return i == 0;
    }
};

//! Using Stack | Greedy Approach
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int k = 0;
        for (int i = 0; i < pushed.size(); i++)
        {
            s.push(pushed[i]);

            // check if pushed value is next to pe popped out
            while (!s.empty() && s.top() == popped[k])
            {
                s.pop();
                k++;
            }
        }
        // if stack is empty means sequence is correct
        return s.empty();
    }
};