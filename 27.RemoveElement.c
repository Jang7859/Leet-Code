#include <stdio.h>
#define MAX 8

// int removeElement(int* nums, int numsSize, int val){
//     int i, j;
//     i=0;
//     for(j=0;j<numsSize;j++){
//         if(nums[j]!=val){
//             nums[i++] = nums[j];
//         }
//     }

//     return i;
// }

int removeElement(int *nums, int numsSize, int val){
    int i, n;
    n = numsSize;
    while(i<n){
        if(nums[i]==val){
            nums[i] = nums[--n];
        }else{
            i++;
        }
    }

    return n;
}

int main(void){

    int nums[MAX] = {0,1,2,2,3,0,4,2};
    int result = removeElement(nums, MAX, 2);
    for(int i=0;i<result;i++){
        printf("%d, ", nums[i]);
    }

    return 0;
}

