#include <stdio.h>
#include <stdlib.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ans = (int*)malloc(sizeof(int)*3);
    ans[0]=-1;
    ans[1]=-1;
    *returnSize = 2;
    if(numsSize==0) return ans;
    
    int l, r, mid;
    l=0; r = numsSize-1;
    
    while(l<=r){
        mid = l + (r - l) / 2;
        
        if(target==nums[mid])
            break;
        
        if(target<nums[mid])
            r=mid-1;
        else
            l=mid+1;
        
    }
    
    l=1; r=1;
    if(nums[mid]==target){
        while(mid-l >= 0 && nums[mid-l] == target) l++;
        while(mid+r <numsSize && nums[mid+r] == target) r++;
        l--;r--;
        
        ans[0] = mid-l;
        ans[1]=mid+r;
    }
    
    return ans;   
    
}

int main(void){

    int arr[6]={5,7,7,8,8,10};
    int size;
    int *result = searchRange(arr, 6, 8, &size);

    for(int i=0;i<size;i++){
        printf("%d ", result[i]);
    }

    return 0;
}