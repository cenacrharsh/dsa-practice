#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=6zhGS79oQ4k&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=3

//! Floor: Largest no. in array <= Target
//! Ceil: Smallest no. in array >= Target -> Lower Bound

int getFloor(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
        {
            ans = arr[mid];
            low = mid + 1; //* as we need larget value <= x
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int getCeil(vector<int> &arr, int n, int x)
{
    //* implementing lower bound
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x)
{
    //* Floor: Largest no. in array <= Target
    //* Ceil: Smallest no. in array >= Target -> Lower Bound
    int floorValue = getFloor(arr, n, x);
    int ceilValue = getCeil(arr, n, x);
    return make_pair(floorValue, ceilValue);
}