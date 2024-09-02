#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Prefix Sum

class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        long long chalkNeededPerCycle = 0;
        for (int chalkPerStudent : chalk)
        {
            chalkNeededPerCycle += chalkPerStudent;
        }

        /*
        long long fullCycles = k / sum; //* since in each cycle we remove sum from k
        k = k - (fullCycles * sum); //* to calc whats left of k then loop over it one last time
        */

        k = k % chalkNeededPerCycle;

        for (int i = 0; i < chalk.size(); i++)
        {
            if (k < chalk[i])
            {
                return i;
            }
            k -= chalk[i];
        }
        return 0;
    }
};