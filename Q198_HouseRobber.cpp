/*
[1,2,3,1]
[ ]

*/
#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> &nums)
{
    int maxVal = nums[0];
    int len = nums.size();
    for (int i = 2; i < len; i++)
    {
        nums[i] = max(nums[i], nums[i] + nums[i - 2]);
        maxVal = max(nums[i], maxVal);
    }
    return max(nums[len - 1], nums[len - 2]);
}

int main(int argc, char const *argv[])
{
    int result;
    vector<int> nums{1, 2};
    result = rob(nums);
    cout << result;
    return 0;
}