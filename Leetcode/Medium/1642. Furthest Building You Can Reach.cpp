#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=zyTeznvXCtg

/*
> Time Complexity: O(N * Log(N))
> Space Complexity: O(N)
*/

//! Using MaxHeap

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        //* we always use bricks but as soon as we run out of bricks but we do have ladders we use max heap to determin what was the maxDiff uptill now and we use ladder there and add as many bricks back, when we run out of both ladders and bricks we stop
        priority_queue<int> pq;
        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            ans = i;
            if (i == heights.size() - 1 || heights[i] >= heights[i + 1])
            {
                continue;
            }
            else
            {
                int diff = heights[i + 1] - heights[i];
                pq.push(diff);
                bricks -= diff;
                if (bricks < 0)
                {
                    int maxDiff = pq.top();
                    pq.pop();
                    bricks += maxDiff;
                    ladders--;
                }
                if (ladders < 0)
                {
                    break;
                }
            }
        }
        return ans;
    }
};