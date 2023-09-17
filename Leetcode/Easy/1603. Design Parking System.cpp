#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class ParkingSystem
{
private:
    vector<int> parkingSlotsAvailable;

public:
    ParkingSystem(int big, int medium, int small)
    {
        parkingSlotsAvailable = {big, medium, small};
    }

    bool addCar(int carType)
    {
        // If space is available, allocate and return True
        if (parkingSlotsAvailable[carType - 1] > 0)
        {
            parkingSlotsAvailable[carType - 1]--;
            return true;
        }

        return false;
    }
};