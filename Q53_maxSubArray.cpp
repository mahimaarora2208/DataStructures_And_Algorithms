/**
 * Kadane's Algorithm - an interative dynamic programming method
 * nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxVal = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] = max(nums[i], nums[i] + nums[i - 1]);
        maxVal = max(nums[i], maxVal);
    }
    return maxVal;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> input{-2,1,-3,4,-1,2,1,-5,4};
    int result = maxSubArray(input);
    cout << "Result: " << result;
    return 0;
}
