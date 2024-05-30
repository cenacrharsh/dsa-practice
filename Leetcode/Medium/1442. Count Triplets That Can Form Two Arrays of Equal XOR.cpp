#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=IAcO4Wyr2ak

//! Prefix Sum & Bit Manipulation

/*
> Time Complexity: O(N^2)
> Space Complexity: O(N)
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        //* we'll have to maintain prefix XOR, XOR b/w index i & j == prefixXOR(j) ^ prefixXOR(i - 1)

        //* if prefixXOR(i) == prefixXOR(k) => prefixXOR b/w index (i + 1) & k == 0 [eg. 0^1 == 0^1^2^3^4 => 2^3^4 == 0]

        //* if the length of subarray b/w index (i + 1) & k == n, then there are (n - 1) good pairs there [eg. 7^2^3^7^2^3 == 0 => 7 = 2^3^7^2^3 because if 7^2^3^7^2^3 == 0 then (7)^(2^3^7^2^3) == 0 and we know a^a == 0 so 7 = 2^3^7^2^3 so on we can make n - 1 combinations], so if len of subarray is N then we can have (N-1) such groups with equal XOR
        
        //* so if prefixXOR(i) == prefixXOR(k) => prefixXOR b/w index (i + 1) & k == 0 => len(i+1 -> k) - 1 pairs => (k - (i + 1) + 1) - 1 pairs = k - i + 1 pairs

        int ans = 0, n = arr.size();
        
        vector<int> prefixXOR(n + 1, 0); //* prefix starts with 0, so one extra index
        for(int i = 0; i < n; i++) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }

        for(int i = 0; i < n; i++) {
            for(int k = i + 1; k <= n; k++) {
                if(prefixXOR[k] == prefixXOR[i]) {
                    ans += k - (i + 1); //* [k - (i + 1) - 1] - 1
                }
            }
        }
        return ans;
    }
};
