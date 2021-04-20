//Greedy  O(n)
/*
bool canJump(int* nums, int numsSize){
    
    if(numsSize==1) return true;
    
    int i, max, temp,k, index;
    index=0; temp = nums[0];
    
    while(temp){
        i=index;
        max = temp;
        temp = 0;
        for(k=1;k<=max;k++){
            if(nums[i+k]==0 && i+k != numsSize-1) continue;
            if(temp<=(nums[i+k]+k)){
                if(i+k+nums[i+k] >= (numsSize-1)) return true;
                
                index = i+k;
                temp =  nums[i+k];
            }
        }
        
    }
    return false;
}
*/

//DP (Bottom-Up)  O(n^2)
/*
bool canJump(int* nums, int numsSize){
    bool dp[numsSize];
    dp[0] = true;
    
    for(int i=1;i<numsSize;i++){
        dp[i] = false;
        for(int j=i-1;j>=0;j--){
            if(dp[j] && nums[j]+j >=i) {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[numsSize-1];
}
*/
//DP (Top-Down)   O(n^2)
/*
bool canJump(int* nums, int numsSize){
    bool dp[numsSize];
    int last = numsSize-1;
    for(int i=numsSize-1;i>=0;i--){
        dp[i] = false;
        if(i+nums[i]>=last){
            dp[i] = true;
            last = i;
        }
    }
    return dp[0];
}
*/
