class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int length = cost.size();
        for (int i = 2; i < length; i++)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]);
            cout << cost[i];
        }
        return min(cost[length - 1], cost[length - 2]);
    }
};