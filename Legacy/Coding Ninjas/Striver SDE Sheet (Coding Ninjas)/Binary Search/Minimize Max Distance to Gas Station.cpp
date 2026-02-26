#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=kMSBvlZ-_HA&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=23

//! Binary Search

/*
> Time Complexity: O(N * log(maxDiff)) + O(N)
> Space Complexity: O(1)
*/

int numOfGasStationsRequired(vector<int> &arr, double maxDist)
{
    int count = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int numbersInBetween = (arr[i] - arr[i - 1]) / maxDist;

        //* if exactly divisible then we do -1, eg. 1/0.5 = 2 but we can only place 1
        if (arr[i] - arr[i - 1] == numbersInBetween * maxDist)
        {
            numbersInBetween--;
        }
        count += numbersInBetween;
    }
    return count;
}

double minimiseMaxDistance(vector<int> &arr, int k)
{
    //* min distance b/w gas stations can be 0, eg. [1, 1, 1] min dist is already 0 and so we place stations at places which already have stations
    //* max distance can be max difference b/w any 2 gas stations

    int n = arr.size();
    double low = 0;
    double high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (double)(arr[i + 1] - arr[i]));
    }

    while (high - low > 1e-6)
    {
        double mid = (low + high) / (2.0);
        int count = numOfGasStationsRequired(arr, mid);

        if (count > k)
        {
            low = mid; //* we need to inc maxDiff allowed
        }
        else
        {
            high = mid; //* if gas stations <= k, then reduce the maxDiff
        }
    }
    return high;

    /*
        // Round off the result to two decimal places
        return round(high * 100) / 100;
    */
}

//! Priority Queue

/*
> Time Complexity: O(N * log(N)) + O(K * log(N))
> Space Complexity: O(N - 1)
*/

double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<double, int>> pq; //* sectionLen -> sectionIndex

    //* place all stations in priority queue
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        pair<double, int> top = pq.top();
        pq.pop();

        int sectionIndex = top.second;

        //* inc count of elements in this section
        howMany[sectionIndex]++;

        double initialSectionLen = arr[sectionIndex + 1] - arr[sectionIndex];
        double newSectionLength = initialSectionLen / (double)(howMany[sectionIndex] + 1);

        //* insert new section in priority queue
        pq.push({newSectionLength, sectionIndex});
    }

    //* the section with max section length will be at top of priority queue
    return pq.top().first;
}

//! Brute Force

/*
> Time Complexity: O(K * N) + O(N)
> Space Complexity: O(N)
*/

double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        double maxSectionLen = -1;
        int maxSectionIndex = -1;

        //* for every new gas station, we decide where it should be placed
        for (int i = 0; i < n - 1; i++)
        {
            double diff = arr[i + 1] - arr[i];
            double currSectionLen = diff / (double)(howMany[i] + 1);
            if (currSectionLen > maxSectionLen)
            {
                maxSectionLen = currSectionLen;
                maxSectionIndex = i;
            }
        }
        howMany[maxSectionIndex]++;
    }

    double maxDistance = -1;
    for (int i = 0; i < n - 1; i++)
    {
        double diff = arr[i + 1] - arr[i];
        double currSectionLen = diff / (double)(howMany[i] + 1);
        maxDistance = max(maxDistance, currSectionLen);
    }
    return maxDistance;
}
