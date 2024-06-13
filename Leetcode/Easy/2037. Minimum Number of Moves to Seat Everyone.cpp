#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=9mO805GuZFI

//! Counting Sort

/*
> Time Complexity: O(K) => K is maxElement of seats/students
> Space Complexity: O(K)
*/

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        vector<int> seatsCount(*max_element(seats.begin(), seats.end()) + 1, 0);
        vector<int> studentsCount(*max_element(students.begin(), students.end()) + 1, 0);

        for(int i = 0; i < n; i++) {
            seatsCount[seats[i]]++;
        }
        for(int i = 0; i < n; i++) {
            studentsCount[students[i]]++;
        }

        int ans = 0;
        int j = 0;
        for(int i = 0; i < seatsCount.size(); i++) {
            //* check if seat is emtpy
            if(seatsCount[i] == 0) {
                continue;
            }

            //* find nearest student if seat is empty
            while(studentsCount[j] == 0) {
                j++;
            }

            ans += abs(i - j);

            seatsCount[i]--;
            studentsCount[j]--;
            
            if(seatsCount[i] != 0) {
                i--; //* for loop would increase value of i
            }
        }
        return ans;
    }
};

//! Sorting

/*
> Time Complexity: O(N * Log(N)) + O(N)
> Space Complexity: O(Log(N))
*/

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        for(int i = 0; i < seats.size(); i++) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};