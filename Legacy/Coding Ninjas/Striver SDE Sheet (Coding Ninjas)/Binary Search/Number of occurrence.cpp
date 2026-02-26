#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=hjR1IYVx9lY&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=5

int firstOccurence(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            //* we'll go left to see if it occurs again
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int secondOccurence(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            //* we'll go right to see if it occurs again
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int firstOcc = firstOccurence(nums, target);
    if (firstOcc == -1)
    {
        return {-1, -1};
    }

    int secondOcc = secondOccurence(nums, target);

    return {firstOcc, secondOcc};
}

int count(vector<int> &nums, int n, int target)
{
    vector<int> numOccurence = searchRange(nums, target);

    if (numOccurence[0] == -1)
    {
        return 0;
    }

    return numOccurence[1] - numOccurence[0] + 1;
}
