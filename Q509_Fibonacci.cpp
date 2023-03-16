class Solution {
public:
    int fib(int n){
        // vector<int>memo(n+1);
        int result = 0;
        if (n == 0){
            return 0;
        } 
        else if(n == 1){
            return 1;
        }
        // memo[0] = 0;
        // memo[1] = 1;
        // for (int i = 2; i <= n; i++){
        //     memo[i] = memo[i-1] + memo[i-2];
        // }
        // return memo[n];  
        return fib(n-1) + fib (n-2);
    };
};