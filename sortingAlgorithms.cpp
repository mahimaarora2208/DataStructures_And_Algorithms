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

void insertionSortRecursion(vector<int> &nums, int n)
{
    // Base Case : only one element
    if (n <= 1)
    {
        return;
    }
    // sort first n-1 elements
    insertionSortRecursion(nums, n - 1);
}

void bubbleSort(vector<int> &nums)
{
    int temp;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = 0; j < nums.size() - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

vector<int> selectionSort(vector<int> &nums)
{
    int minIdx;
    int temp;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        minIdx = i;
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            temp = nums[i];
            nums[i] = nums[minIdx];
            nums[minIdx] = temp;
        }
    }
    return nums;
}

void merge(vector<int> &leftArray, vector<int> &rightArray, vector<int> &array)
{
    int leftSize = leftArray.size();
    int rightSize = rightArray.size();
    int i = 0, l = 0, r = 0; // declaring indices

    // check conditions for merging
    while (l < leftSize && r < rightSize)
    {
        if (leftArray[l] < rightArray[r])
        {
            array[i] = leftArray[l];
            l++;
            i++;
        }
        else // takes equal case as well
        {
            array[i] = rightArray[r];
            r++;
            i++;
        }
    }
    // eg. L = [1,2,3] R =[4,5,6] : in this case, all the left will get over but above while loop exits without
    // touching the right array. Hence, we need the code written below.
    while (l < leftSize)
    {
        array[i] = leftArray[l];
        l++;
        i++;
    }
    while (r < rightSize)
    {
        array[i] = rightArray[r];
        r++;
        i++;
    }
}

void mergeSort(vector<int> &nums)
{
    int length = nums.size();
    int middle = length / 2;
    vector<int> L(middle);          // define L vector of size middle
    vector<int> R(length - middle); // define R vector of size (length - middle)

    // base condition to stop recursion
    if (length <= 1)
    {
        return;
    }

    int i = 0, j = 0; // declaring counters for-loop
    // copy elements of nums in L and R
    for (; i < length; i++)
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
    mergeSort(L);
    mergeSort(R);
    merge(L, R, nums);
}

int main(int argc, char const *argv[])
{
    vector<int> nums1{3, 7, 8, 5, 4, 2, 6, 1};
    mergeSort(nums1);
    printResult(nums1);
    return 0;
}
