#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Modified Binary Search

/*
> Time Complexity: O(m * log(m)) + O(n * log(m)) => to sort the potions arr + apply binary search on potions arr for each value in spells arr
> Space Complexity: O(n) => where n is the size of spells array, and we need arr of size n to store our ans
*/

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for (long long spell : spells)
        {
            int low = 0, high = potions.size() - 1, count = 0;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (spell * potions[mid] >= success)
                {
                    // count = count + (high - mid + 1); // add the elements to right of mid in each iteration
                    count = potions.size() - mid; // directly get the size of the array from mid -> end
                    high = mid - 1;
                }
                else if (spell * potions[mid] < success)
                {
                    low = mid + 1;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

//* original
class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for (long long spell : spells)
        {
            int low = 0, high = potions.size() - 1, index = potions.size();
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (spell * potions[mid] >= success)
                {
                    if (mid - 1 >= low && spell * potions[mid - 1] >= success)
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        index = mid;
                        break;
                    }
                }
                else
                {
                    // target < success
                    low = mid + 1;
                }
            }
            cout << "For: " << spell << " index in potion is: " << index << endl;
            ans.push_back(potions.size() - index);
        }
        return ans;
    }
};