#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=SCz-1TtYxDI&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=26

/*
> Time Complexity: O(n * log (m) base 2)
> Space Complexity: O(1)
*/

//* low starts from not possible values, high starts form possible values
int countFirstOccOfOne(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            high = mid - 1; //* we'll go left to see if it occurs again
        }
        else if (target > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int maxCount = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int currCount = m - countFirstOccOfOne(matrix[i], 1);
        if (currCount > maxCount)
        {
            maxCount = currCount;
            index = i;
        }
    }
    return index;
}