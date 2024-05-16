#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=pBWCOCS636U&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=2

//! Sliding Window

/*
> Time Complexity: O(2K)
> Space Complexity: O(1)
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int cardSum = 0, maxCardSum = 0;
        for(int i = 0; i < k; i++) {
            cardSum += cardPoints[i];
        }
        maxCardSum = max(maxCardSum, cardSum);
        int left = k - 1, right = cardPoints.size() - 1;
        while(left >= 0) {
            cardSum -= cardPoints[left];
            left--;
            cardSum += cardPoints[right];
            right--;
            maxCardSum = max(maxCardSum, cardSum);
        }
        return maxCardSum;
    }
};