#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Max Heap

// # Tutorial: https://www.youtube.com/watch?v=KytaqLXEeJA

/*
> Time Complexity: O(N * Log(N)) + O(N * Log(K)) -> Sorting + Traverse in array and push in PQ every time
> Space Complexity: O(Log(N) + K) -> Sorting + Heap
*/

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        //> first we fix one person whom we'll pay minimum wage possible and then we'll pay all the others maintaining the ratio we got from paying that person the minimum wage, so wage[i]/quality[i] will give us the ratio of money being paid to this guy which is minimum now we calculate maintaining this ratio how much we have to pay others. We don't know which person to fix so we have to try calc the ratio for all of them, but one thing is sure that it's better for us to go with lower ratios as if we go higher everybody has to be paid in accordance to that ratio so after calculating the ratio we sort it in descending order but ratio alone would not solve our problem as maybe the ratio is low but while selecting K workers we have to pick the one worker with highest ratio as else he'll go underpaid, so we might have worker whose quality is high and hence we'll end up paying lots of money so after sorting with ratio when we move left to right and decide which K workers to keep we let go of workers with highest quality as they have to be paid the most.

        //* Step 1: Calculate ratio of Wage/Quality
        //* Step 2: Sort in asc order a/q ratio and maintain quality as well, wage no longer required as money given to worker would be his quality * max ratio among the K selected workers
        //* Step 3: Maintain a max heap based on quality, so that when heap exceeds size K we let go the one with the highest quality

        int n = wage.size();
        vector<pair<double, int>> workers; //* wage to quality ratio->quality
        for (int i = 0; i < n; i++)
        {
            workers.push_back({(double)wage[i] / (double)quality[i], quality[i]});
        }
        sort(workers.begin(), workers.end());

        priority_queue<int> pq; //* max heap to store k minimum qualities
        double totalQuality = 0;
        double ans = DBL_MAX;
        for (int i = 0; i < n; i++)
        {
            double currentRatio = workers[i].first; //* as we move from left to right our ratio increases and we always have to consider the max ratio
            int currentQuality = workers[i].second;

            //* add current quality to heap and calculate total quality
            totalQuality += currentQuality;
            pq.push(currentQuality);

            //* remove maximum quality if size of heap exceeds k
            if (pq.size() > k)
            {
                totalQuality -= pq.top();
                pq.pop();
            }

            //* calculate the total sum for current set of k workers
            if (pq.size() == k)
            {
                ans = min(ans, totalQuality * currentRatio);
            }
        }
        return ans;
    }
};