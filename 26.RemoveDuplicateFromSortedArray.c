#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0)
        return 0;
    
    int i=0, j;
    for(j=1;j<numsSize;j++){
        if(nums[i]!=nums[j])
            nums[++i]=nums[j];        
    }
    
    return i+1;
    
}

int main(void){

    int arr[5]={1,1,2,3,3};
    printf("%d\n", removeDuplicates(arr, 5));
    for(int i=0;i<5;i++){
        printf("%d", arr[i]);
    }

    return 0;
}