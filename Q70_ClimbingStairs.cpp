/*
Resource: https://www.enjoyalgorithms.com/blog/climbing-stairs-problem
*/
/*
RECURSION - Fails when n == 44 or more. Time limit exeeded
Class Solution {
public:
    int climbStairs(int i, int n) {
        // base cases
        if (i > n){
            return 0;
        }
        else if (i == n){
           return 1;
        }
    return climbStairs(i+1,n) + climbStairs(i+2,n);
    }
    int climbStairs(int n) {
        //cs(0,n) = cs(1,n) +cs(2,n)
        //cs(1,n) = cs(2,n) +cs(3,n)
        //cs(5,n) = cs(3,n) +cs(5,n)

        return climbStairs(0, n);
    }
};*/

// Dynamic Programming - PASSES for large n
class Solution
{
public:
    int climbStairs(int n)
    {
        // if n == 0, stairs[n+1] will give index out of bound for stairs[2]
        if (n == 0)
        {
            return 0;
        }
        // if n == 1, stairs[n+1] will give index out of bound for stairs[2]
        if (n == 1)
        {
            return 1;
        }
        int stairs[n + 1]; // Create an int array which stroes unique ways to climb stairs [0:0 ; 1:1; 2:2; 3:3; 4:5; 5:8]
        // base cases
        stairs[0] = 0;
        stairs[1] = 1;
        stairs[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            stairs[i] = stairs[i - 1] + stairs[i - 2];
        }
        return stairs[n];
    }
};
