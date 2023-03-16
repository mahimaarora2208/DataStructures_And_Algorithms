/**

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

int minCost(string colors, vector<int> &neededTime)
{
    int total = 0;
    int currMax = 0;
    for (int i = 0; i < neededTime.size(); i++)
    {
        if (i > 0 && colors[i] != colors[i - 1])
        {
            currMax = 0; // reset
        }
        total += min(currMax, neededTime[i]);
        currMax = max(currMax, neededTime[i]);
    }
    return total;
}

int main(int argc, char const *argv[])
{
    int result;
    vector<int> time{1, 2, 3, 4, 1};
    string str = "aabaa";
    result = minCost(str, time);
    cout << result;
    return 0;
}
