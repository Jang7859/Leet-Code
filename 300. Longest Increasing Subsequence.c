//O(n log(n))

int findIndex(int dp[], int l, int r, int target){
    if(l<=r){
        int mid = l+(r-l)/2;
        if(dp[mid]==target) return mid;
        else if(dp[mid]>target) return findIndex(dp, l, mid-1, target);
        else return findIndex(dp, mid+1, r, target);
    }
    
    return l;
}

int lengthOfLIS(int* nums, int numsSize){
    int dp[numsSize];
    int k=-1;
    for(int i=0;i<numsSize;i++){
        if(i==0 || dp[k]<nums[i]){
            dp[++k] = nums[i];
        }else{
            int idx = findIndex(dp, 0, k, nums[i]);
            dp[idx] = nums[i];
        }
    }
    for(int q=0;q<=k;q++){
        printf("%d ", dp[q]);
    }
    
    return k+1;
}

//DP, Time complex : (O(n^2)).
/*
int max(int a, int b){
    return a>b ? a: b;
}

int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0) return 0;
    
    int dp[numsSize];
    int k=0;
    dp[k] = 1;
    int ans = 1;
    for(int i=1;i<numsSize;i++){
        int val = 0;
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                val = max(val, dp[j]);
            }
        }
        dp[i] = val+1;
        ans = max(ans, dp[i]);
    }
    return ans;
}
*/

//DP, time complex : O(n^3).
/*
int lengthOfLIS(int* nums, int numsSize){
    int max=1;
    int dp[2501][2501];
    for(int i=0;i<numsSize;i++){
        dp[i][i] = 1;
        for(int j=i+1;j<numsSize;j++){
            dp[i][j] = 1;
            if(nums[i]>=nums[j]) continue;
            dp[i][j]+=1;
            for(int k=j-1;k>=i;k--){
                if(nums[i]<nums[k] && nums[k]<nums[j])
                    if(dp[i][j]<dp[i][k]+1){
                        dp[i][j] = dp[i][k]+1;  
                    }
            }
            if(dp[i][j]>max) max = dp[i][j];
        }
    }
    
    return max;
}
*/








