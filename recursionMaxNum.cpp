/**
 * ----------------------------
 * SORTING ALGORITHMS
 * ----------------------------
 *
 * 1. Insertion Sort (in-place) | Time complexity : O(n) to O(n^2) | Space Complexity : O(1)
 * 2. Selection Sort (in-place) | Time complexity : O(n^2) | Space Complexity : O(1)
 * 3. Merge Sort (recursion) | Time complexity : O(nlogn) | Space Complexity : O(n)
 * 4. Insertion Sort (recursion) | Time complexity : O(n) to O(n^2) | Space Complexity : O(1)
 * 5. Bubble Sort (in-place) | Time complexity : O(n) to O(n^2) | Space Complexity : O(1)
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

int findMaxNumber(vector<int> &nums)
{
    // see if you need to exit
    // otherwise recurse
    // 1 2 | 3 4 ; 1 | 2
    int leftMax, rightMax;
    int middle = nums.size() / 2;
    vector<int> L(middle);
    vector<int> R(nums.size() - middle);
    // base case
    if (nums.size() <= 1)
    {
        return nums[0];
    }
    int i = 0, j = 0; // declaring counters for-loop
    // copy elements of nums in L and R
    for (; i < nums.size(); i++)
    {
        if (i < middle)
        {
            L[i] = nums[i];
        }
        else
        {
            R[j] = nums[i];
            j++;
        }
    }
    leftMax = findMaxNumber(L);
    rightMax = findMaxNumber(R);

    if (leftMax < rightMax)
    {
        return rightMax;
    }
    else
    {
        return leftMax;
    }
}

int findMaxNumberTyler(vector<int> &nums) {
	// base case
	if (nums.size() <= 1) {
		return nums[0];
	}

	// recursive case
	int firstNumber = nums[0];
	vector<int> otherNumbers;
	for (int i=1; i < nums.size(); i++) {
		otherNumbers.push_back(nums[i]);
	}

	int maxOfOthers = findMaxNumber(otherNumbers);
	if (firstNumber > maxOfOthers) {
		return firstNumber;
	} else {
		return maxOfOthers;
    }
}
	

int main(int argc, char const *argv[])
{
    vector<int> nums1{1, 2, 3, 4, 76, 33, 5555};
    int result = findMaxNumberTyler(nums1);
    cout << result;
    return 0;
}
