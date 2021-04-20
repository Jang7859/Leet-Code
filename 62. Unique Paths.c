int solve(int *count, int x, int y, int m, int n, int **dp){
    
    if(x==n-1 && y==m-1) return 1; // Goal!
    if(x>=n||y>=m) return 0; //out of range
    if(dp[y][x]!=0) return dp[y][x]; // search completed.
    
    dp[y][x] = solve(count, x+1, y, m, n, dp) + solve(count, x, y+1, m, n, dp);
    
    
    return dp[y][x];
}

int uniquePaths(int m, int n){
    int count=0;
    int **dp = (int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
        dp[i] = (int*)calloc(n, sizeof(int));
    }
    count = solve(&count, 0,0,m,n, dp);
    
    return count;
}