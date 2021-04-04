#include <stdio.h>

/*Brute force*/
// int findKthLargest(int* nums, int numsSize, int k){
//     int max, i, j, index;
//     for(i=0;i<k;i++){
//         max = -2147483648;
//         for(j=0;j<numsSize;j++){
//             if(nums[j]>max){
//                 index = j;
//                 max = nums[j];
//             }
//         }
//         nums[index] = -2147483648;
//     }
//     return max;
// }

int findKthLargst(int * nums, int numsSize, int k){



}

int main(void){
    int arr[6]={3,2,1,5,6,4};
    printf("%d\n", findKthLargest(arr, 6, 3));

    return 0;
}