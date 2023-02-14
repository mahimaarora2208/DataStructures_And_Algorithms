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
 * -------------------------------
 * Time Complexity
 * -------------------------------
 * 1. Maximum Sub Array Using Kadane's (in-place) | Time complexity : O(n) | Space Complexity : O(1)
 * 2. Maximum Sub Array Using Recursion | Time complexity : O(n) to O(nlogn) | Space Complexity : O(1)
 *
 *
 */

#include <iostream>
#include <vector>
using namespace std;

// helper function for printing array
void printResult(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
}

int maxSubArrayKadane(vector<int> &nums)
{
    int maxVal = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] = max(nums[i], nums[i] + nums[i - 1]);
        maxVal = max(nums[i], maxVal);
    }
    return maxVal;
}

int findCrossArray(vector<int> array, int l, int m, int h)
{
    int best_sum = array[m] + array[m + 1];
    int max_left = m;
    int max_right = m + 1;
    int sum = best_sum;
    for (int i = m - 1; i < l; i++)
    {
        sum = sum + array[i];
        if (sum > best_sum)
        {
            best_sum = sum;
            max_left = i;
        }
    }
    sum = best_sum;

    for (int i = m + 2; i < h; i++)
    {
        sum = sum + array[i];
        if (sum > best_sum)
        {
            best_sum = sum;
            max_right = i;
        }
    }

    return best_sum;
}

int maxSubArrayRecursion(vector<int> &nums, int &l, int &h)
{
    int m = (l + h) / 2;
    int left_sum = INT_MIN, right_sum = INT_MIN, cross_sum = INT_MIN;
    // Base Case : only one element
    if (l == h)
    {
        return nums[l];
    }

    left_sum = maxSubArrayRecursion(nums, l, m);
    right_sum = maxSubArrayRecursion(nums, l, m);
    cross_sum = findCrossArray(nums, l, m, h);

    if (left_sum >= right_sum && left_sum >= cross_sum)
    {
        return left_sum;
    }
    else if (right_sum >= left_sum && right_sum >= cross_sum)
    {
        return right_sum;
    }
    else
    {
        return cross_sum;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> input{1, -2, 3, 4, -5, -6}; //-2,1,-3,4,-1,2,1,-5,4
    int l = 0;
    int h = input.size() - 1;
    int result = maxSubArrayRecursion(input, l, h);
    cout << "Result: " << result;
    // printResult(result);
    return 0;
}
