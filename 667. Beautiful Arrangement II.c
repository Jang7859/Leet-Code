/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructArray(int n, int k, int* returnSize){
    int *ans = (int*)malloc(sizeof(int)*n);
    int i=0;
    *returnSize=n;
    ans[i] = 1;
    
    while(k){
        
        if(!(i%2)) ans[i+1] = ans[i]+k;
        
        if(i%2) ans[i+1] = ans[i]-k;
        
        i++;
        k--;
        
    }
    
    for(int j=i+1;j<n;j++){
        ans[j] = j+1;
    }       
    
    return ans;
    
}