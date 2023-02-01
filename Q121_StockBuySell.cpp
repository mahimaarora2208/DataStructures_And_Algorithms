/**
 * Input: prices = {7,1,5,3,6,4}
 * Need: Max Profit --> max(prices[i] - prices[i-1]
 * e.g. 1-7 = -6 ; 5-1 = 4 .....6-1 = 5 but prices[i-1] needs to be the minimum value.
 * Use kadane's algorithm to update prices[i] to minimum value
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minVal = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++){
        profit = max(profit, prices[i] - prices[i-1]);
        prices[i] = min(prices[i], prices[i-1]);
        minVal = min(prices[i], minVal);
    }
    return profit;
       
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> input{7,1,5,3,6,4}; 
    int result = maxProfit(input);
    cout << "Result: " << result;
    return 0;
}
