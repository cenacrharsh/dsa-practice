#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=1c5HnSKNABA

//! Bit Manipulation

//> without flipping the bits

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        //* we won't actually flip any bits but we have to assume that first row is always containing ones and hence other elements in the row would be flipped if originally first col element did'nt have a 1
        int ans = 0;
        ans += row * (1 << (col - 1 - 0)); //* contribution of first column
        for(int j = 1; j < col; j++) {
            int numOfOnes = 0;
            for(int i = 0; i < row; i++) {
                if((grid[i][0] == 1 && grid[i][j] == 1) || (grid[i][0] == 0 && grid[i][j] == 0)) {
                    numOfOnes++;
                }
            }
            
            int numOfZeroes = row - numOfOnes;
            ans += max(numOfOnes, numOfZeroes) * (1 << (col - 1 - j));
        }
        return ans;
    }
};

//> fipping the bits

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();

        //* in binary representation the left most bit has highest priority so our first goal is to flip the entire row if the first element is 0, so in the end result the first col should only have 1's
        for(int i = 0; i < row; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < col; j++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        //* now we traverse from 2 col till the end, and in each row if num(1) > num(0) we leave it be but if 0's are > 1's we flip it to have maximum sum
        for(int j = 1; j < col; j++) {
            int numOfOnes = 0;
            for(int i = 0; i < row; i++) {
                if(grid[i][j] == 1) {
                    numOfOnes++;
                }
            }
            
            int numOfZeroes = row - numOfOnes;
            if(numOfOnes < numOfZeroes) {
                for(int i = 0; i < row; i++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        //* the contribution of each element is 2^(m - 1 - j) where j is the column number
        int ans = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                ans += grid[i][j] * (1 << (col - 1 - j));
            }
        }
        return ans;
    }
};
