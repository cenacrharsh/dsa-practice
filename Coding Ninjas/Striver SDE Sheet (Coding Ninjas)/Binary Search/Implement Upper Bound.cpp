#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=6zhGS79oQ4k&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=3

/*
> Time Complexity: O(log (n) base 2)
> Space Complexity: O()
*/

int upperBound(vector<int> arr, int n, int x)
{
    //* smallest index i where arr[i] > x
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;

    //! STL
    //@ return upper_bound(arr.begin(), arr.end(), x) - arr.begin();
}
