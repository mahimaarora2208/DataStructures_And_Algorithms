/**
 * ----------------------------
 * SORTING ALGORITHMS
 * ----------------------------
 *
 * 1. Insertion Algorithm (in-place) | Time complexity : O() | Space Complexity : S()
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> &nums)
{
    int j;
    int temp;
    for (int i = 1; i < nums.size(); i++)
    {
        j = i;
        while (j > 0 && nums[j - 1] > nums[j])
        {
            temp = nums[j - 1];
            nums[j - 1] = nums[j];
            nums[j] = temp;
            j = j - 1;
        }
    }
    return nums;
}

int main(int argc, char const *argv[])
{
    vector<int> nums1{5, 6, 1, 2, 90, 1111};
    vector<int> result = insertionSort(nums1);
    cout << result[1];
    return 0;
}
