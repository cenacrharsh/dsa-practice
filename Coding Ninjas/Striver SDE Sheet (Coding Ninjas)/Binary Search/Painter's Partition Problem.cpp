#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=thUd_WJn6wk&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=20&t=14s

/*
> Time Complexity: O(log (sum - max) base 2) * O(N)
> Space Complexity: O(1)
*/

int countPainters(vector<int> &boards, int maxSum)
{
    int painters = 1;
    int totalSum = 0;
    for (int i = 0; i < boards.size(); i++)
    {
        if (totalSum + boards[i] > maxSum)
        {
            painters++;
            totalSum = boards[i];
        }
        else
        {
            totalSum += boards[i];
        }
    }
    return painters;
}

//* low starts from not possible values as we need to go higher to be able to split work among k painters, while high starts from possible values
int findLargestMinDistance(vector<int> &boards, int k)
{
    //* min area covered has to be the largest element of the array
    //* max area covered has to be the sum of all elements

    //* if no of partitions required > size of array
    if (k > boards.size())
    {
        return -1;
    }

    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int numOfPainters = countPainters(boards, mid);

        //* if no of painters is > k means we need to reduce the max araa allowed
        if (numOfPainters <= k)
        {
            high = mid - 1; //* as we want lowest possible value of max area
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}