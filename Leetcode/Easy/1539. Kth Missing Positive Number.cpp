#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Binary Search

/*
> Time Complexity: O(log (N) base 2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        //* we'll calc the number of integers missing at each index and then apply BS to figure out k lies in b/w which 2 elements

        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1); //* considering 0 based indexing at index i, (i+1)th element exists
            if (missing < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        //* high ends up to the left of low and in some cases can even end up at index -1 eg. [4, 7, 9] k = 3
        //* kth missing = arr[high] + more req = arr[high] + (k - missing) = arr[high] + (k - (arr[high] - (high + 1))) = high + 1 + k = low + k (at the end low ends up just after high so low = high + 1)
        return k + high + 1; //* low + k
    }
};

//! Brute Force
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        //* every integer < k will take one place
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= k)
            {
                k++;
            }
            else
            {
                break;
            }
        }
        return k;
    }
};