#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int poisonousPlants(vector<int> &plants)
{
    int n = plants.size();
    vector<int> days(n, 0); // Days each plant survives
    stack<int> stk;         // Monotonic stack to track indices
    int maxDays = 0;

    for (int i = 0; i < n; ++i)
    {
        int maxSurviveDays = 0;

        // Pop elements from the stack while the current plant has less pesticide
        while (!stk.empty() && plants[stk.top()] >= plants[i])
        {
            maxSurviveDays = max(maxSurviveDays, days[stk.top()]);
            stk.pop();
        }

        // If the stack is not empty, the current plant dies after surviving maxSurviveDays + 1 days
        if (!stk.empty())
        {
            days[i] = maxSurviveDays + 1;
        }

        stk.push(i);                     // Push current plant index to the stack
        maxDays = max(maxDays, days[i]); // Update the maximum days
    }

    return maxDays;
}

int main()
{
    vector<int> plants = {6, 5, 8, 4, 7, 10, 9};
    cout << "Days after which no plant dies: " << poisonousPlants(plants) << endl;
    return 0;
}