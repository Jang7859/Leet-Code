#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>




int compare(const void *a, const void *b){
    int l = *(const int*)a;
    int r = *(const int*)b;

    return l-r;
}

int threeSumClosest(int* nums, int numsSize, int target){
    int i, sum, result, min_diff, diff, pre_diff;
    sum = 0; result = nums[0]+nums[1]+nums[2];
    
    min_diff = 2147483647;

    qsort((void*)nums, numsSize, sizeof(nums[0]), compare);

    int l, r;
    for(i=0;i<numsSize-2;i++){
        l = i+1;
        r = numsSize-1;
        diff=2147483647;
        while(l<r){
            sum = nums[i]+nums[l]+nums[r];
            pre_diff=diff;
            diff = abs(target-sum);
            if(diff == 0)
                return sum;
            
            if(diff<min_diff){
                min_diff = diff;
                result = sum;
            }

            if(sum<target){
                while(l<r && nums[l]==nums[l+1])
                    l++;
                l++;
            }else{
                while(l<r && nums[r]==nums[r-1])
                    r--;
                r--;
            }
        }
    } 

    return result;
     
}

int main(void){

    int nums[13]={-55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33};
    printf("%d\n",threeSumClosest(nums, 13, 0));
    return 0;
}