#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=6zhGS79oQ4k&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=3

int lowerBound(vector<int> arr, int n, int x)
{
    //* Smallest index i where arr[i] >= x
    int low = 0, high = n - 1;
    int ans = n; //* if no element >= x exists in array
    while (low <= high)
    {
        int mid = (low + high) / 2;
        //* maybe an ans
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1; //* look for smaller index on left
        }
        else
        {
            low = mid + 1; //* look for possible ans on right
        }
    }
    return ans;
}
