/**
 * 
 * --------------------------------------------------
 * Easy Python solution
 * ---------------------------------------------------
 * class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        count = 0
        while(count < n):
            nums1[m + count] = nums2[count]
            count = count + 1
        nums1.sort()
        
 */

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int p1 = m - 1, p2 = n - 1, i = m + n - 1;
    while (p2 >= 0)
    {
        if (p1 >= 0 && nums1[p1] > nums2[p2])
        {
            nums1[i] = nums1[p1];
            i--;
            p1--;
        }
        else
        {
            nums1[i] = nums2[p2];
            i--;
            p2--;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums1{1, 2, 2, 1};
    vector<int> nums2{2};
    vector<int> result = merge(nums1, nums2);
    return 0;
}
