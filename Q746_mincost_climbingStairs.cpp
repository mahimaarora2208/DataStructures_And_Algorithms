/*
 [ 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 ]
 [ 1, 100, 2, 3, 3, 103, 4, 5, 104, 6 ]
*/
#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int len = cost.size();
    for (int i = 2; i < len; i++)
    {
        cost[i] += min(cost[i - 1], cost[i - 2]);
    }
    return min(cost[len - 1], cost[len - 2]);
}

int main(int argc, char const *argv[])
{
    int result;
    vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    result = minCostClimbingStairs(cost);
    cout << result;
    return 0;
}