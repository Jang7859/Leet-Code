//DP (for) (Bottom-Up approach)
/*
int fib(int n){
    int dp[31];
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
*/

//Recursive(DP) (Top-down approach)
int dp[31];
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    
    if(dp[n]==0){
        dp[n] = fib(n-1) + fib(n-2);
    }
    
    return dp[n];
}

//Recursive
/*
int fib(int n){    
    if(n==0) return 0;
    if(n==1) return 1;
    
    return fib(n-1) + fib(n-2);
}
*/