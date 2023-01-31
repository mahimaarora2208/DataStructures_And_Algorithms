/**
 * Kadane's Algorithm - an interative dynamic programming method
 * nums = [1,-2,3,4,-5,6]
 * -------------
 * Pseudocode
 * ------------- 
 *  
 *  - Declare a variable which holds the max sum [maxVal]
 *  - Read the vector using for loop for(i < len(nums))
 *  - Change i th value in vector with max --> max(nums[i], nums[i-1]) : here nums[i-1] will be sum until that ith value
 *  - Change maxVal variable if nums[i] > maxVal
 *  - Keep going until end 
 *  - return maxVal
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
    vector<int> input{1,-2,3,4,-5,6}; //-2,1,-3,4,-1,2,1,-5,4
    int result = maxSubArray(input);
    cout << "Result: " << result;
    return 0;
}
