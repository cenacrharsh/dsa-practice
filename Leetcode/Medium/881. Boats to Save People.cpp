#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N * log(N)) => we are sorting peoples array
> Space Complexity: O(1)
*/

/*
Assume there are four sorted weights a, b, c, d, and a boat weight limit of k.
Now the question is : while finding a match for d, if we found that b is the heaviest who can fit in the boat along with d, why are we going with a instead of b? wouldn't going with b save some more space for the next boat so that c can be matched with a and doesn't require a separate boat to travel alone? The answer is it wouldn't, because c will always get matched with b if d is matched with a)

So, mathematically the problem boils down to:
Given a <= b <= c <= d and b + d <= k prove that b + c <=k.

Proof: Since b + d <= k, and c <= d, we can safely say that b + c <=k.
*/

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int count = 0;
        int left = 0, right = people.size() - 1;
        while (left <= right)
        {
            //* if possible we will take heaviest and lightest together, else we'll take the heaviest separately
            if (people[left] + people[right] <= limit)
            {
                left++;
            }
            count++;
            right--;
        }
        return count;
    }
};