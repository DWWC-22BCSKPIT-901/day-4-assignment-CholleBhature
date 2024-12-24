#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int longestSubsequence(vector<int> &nums, int k)
{
    map<int, int> dp; // dp[value] stores the length of the longest subsequence ending with value
    int maxLength = 0;

    for (int num : nums)
    {
        // Check for possible predecessors within the range [num - k, num - 1]
        int maxPrevLength = 0;
        for (int i = num - k; i < num; ++i)
        {
            if (dp.find(i) != dp.end())
            {
                maxPrevLength = max(maxPrevLength, dp[i]);
            }
        }

        dp[num] = maxPrevLength + 1;         // Update the current number's subsequence length
        maxLength = max(maxLength, dp[num]); // Update the global maximum length
    }

    return maxLength;
}

int main()
{
    vector<int> nums = {3, 10, 2, 1, 20};
    int k = 10;

    cout << "Length of longest subsequence: " << longestSubsequence(nums, k) << endl;

    return 0;
}