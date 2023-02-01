/**
 * Input: prices = {7,1,5,3,6,4}
 * Need: Max Profit --> max(prices[i] - minVal)
 * e.g. 1-7 = -6 ; 5-1 = 4 .....6-1 = 5
 * Use kadane's algorithm to get minVal
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minVal = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++){
        profit = max(profit, prices[i] - minVal);
        minVal = min(prices[i], minVal);
    }
    return profit; 
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> input{7,6,5,4,3,2,1}; 
    int result = maxProfit(input);
    cout << "Result: " << result;
    return 0;
}
