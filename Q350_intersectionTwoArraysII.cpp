/**
 *
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    int minArr = min(nums1.size(), nums2.size());
    int count = 0;
    vector<int> result;

    for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    if (result.size() != minArr)
                    {
                        result.push_back(nums1[i]);
                        count++;
                    }
                    else{
                        break;
                    }  
                }
            }
        }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> nums1{1, 2, 2, 1};
    vector<int> nums2{2};
    vector<int> result = intersect(nums1, nums2);
    return 0;
}
