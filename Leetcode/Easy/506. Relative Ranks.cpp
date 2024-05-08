#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        priority_queue<pair<int, int>> pq; //* a max heap to store value->index
        for (int i = 0; i < score.size(); i++)
        {
            pq.push(make_pair(score[i], i));
        }
        vector<string> ans(score.size());
        for (int i = 0; i < score.size(); i++)
        {
            int index = pq.top().second;
            pq.pop();

            string pos = "";
            if (i == 0)
            {
                pos = "Gold Medal";
            }
            else if (i == 1)
            {
                pos = "Silver Medal";
            }
            else if (i == 2)
            {
                pos = "Bronze Medal";
            }
            else
            {
                pos = to_string(i + 1);
            }

            ans[index] = pos;
        }
        return ans;
    }
};