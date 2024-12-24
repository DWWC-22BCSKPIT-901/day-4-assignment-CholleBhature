#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findStartingPetrolPump(vector<pair<int, int>> &petrolPumps)
{
    int totalPetrol = 0, totalDistance = 0;
    int currentPetrol = 0, startIndex = 0;

    for (int i = 0; i < petrolPumps.size(); ++i)
    {
        totalPetrol += petrolPumps[i].first;
        totalDistance += petrolPumps[i].second;
        currentPetrol += petrolPumps[i].first - petrolPumps[i].second;

        // If current petrol becomes negative, reset start index
        if (currentPetrol < 0)
        {
            startIndex = i + 1;
            currentPetrol = 0;
        }
    }

    // Check if the tour is possible
    return (totalPetrol >= totalDistance) ? startIndex : -1;
}

int main()
{
    vector<pair<int, int>> petrolPumps = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    int startIndex = findStartingPetrolPump(petrolPumps);

    if (startIndex != -1)
    {
        cout << "Start at petrol pump: " << startIndex << endl;
    }
    else
    {
        cout << "No solution possible." << endl;
    }

    return 0;
}