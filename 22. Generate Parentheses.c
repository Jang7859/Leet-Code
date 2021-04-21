void solve(char*** ans, char arr[], int left, int right, int n, int* returnSize){
    
    if(left>n || left<right) return;
    if(left+right==(n*2)){
        
        (*ans)[*returnSize] = (char*)malloc(sizeof(char)*(n*2+1));
        memcpy((*ans)[*returnSize], arr, sizeof(char)*(n*2));
        (*ans)[*returnSize][n*2] = NULL;
        *returnSize += 1;
        return;
    }
    

    for(int i=0;i<2;i++){
        if(!(i%2)){
            arr[left+right] = '(';
            solve(ans, arr, left+1, right, n, returnSize);
        }else{
            arr[left+right] = ')';
            solve(ans, arr, left, right+1, n, returnSize);
        }
    }
}

char ** generateParenthesis(int n, int* returnSize){
    char arr[n*2];
    char **ans = (char**)malloc(sizeof(char*)*(n*1000));
    *returnSize=0;
    solve(&ans, arr, 0, 0, n, returnSize);
    return ans;
    
}