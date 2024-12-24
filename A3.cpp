#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Fallback GCD function (if <numeric>'s gcd is unavailable)
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

vector<int> gcdQuery(const vector<int> &nums, const vector<int> &queries)
{
    vector<int> gcdPairs;
    int n = nums.size();

    // Generate all GCD pairs
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            gcdPairs.push_back(gcd(nums[i], nums[j]));
        }
    }

    // Sort the GCD pairs
    sort(gcdPairs.begin(), gcdPairs.end());

    // Answer the queries
    vector<int> answer;
    for (int q : queries)
    {
        if (q >= 0 && q < gcdPairs.size())
        {
            answer.push_back(gcdPairs[q]);
        }
        else
        {
            answer.push_back(-1); // Handle out-of-range queries
        }
    }

    return answer;
}

int main()
{
    vector<int> nums = {10, 15, 20};
    vector<int> queries = {0, 2, 5};

    vector<int> result = gcdQuery(nums, queries);

    cout << "Results: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
