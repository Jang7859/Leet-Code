#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparator(const void *a, const void *b)
{
    int l = *(const int*)a;
    int r = *(const int*)b;
    return l-r;
}
int** threeSum(int* nums, int numsSize, int *returnSize) 
{
    if(nums==NULL || numsSize==0)
        return NULL;
    int i, count;
    int **result = NULL;
    count = 0;

    qsort((void*)nums, numsSize, sizeof(nums[0]), comparator);

    int now, left, right, sum;
    for(i=0;i<numsSize;i++){
        now = i;
        left = i+1;
        right = numsSize-1;
        
        if(i>0 && nums[i]==nums[i-1])
            continue;
        
        while(left<right){
            sum = nums[i]+nums[left]+nums[right];
            if(sum==0){
                count++;
                result = (int**)realloc(result, sizeof(int*)*count);
                result[count-1] = (int*)malloc(sizeof(int)*3);
                result[count-1][0] = nums[now];
                result[count-1][1] = nums[left];
                result[count-1][2] = nums[right];

                while(left<right && nums[left]==nums[left+1])
                    left++;
                while(left<right && nums[right]==nums[right-1])
                    right--;
                
                left++;
                right--;
            }else if(sum<0){
                left++;
            }else{
                right--;
            }
        }
    }
    *returnSize = count;
    return result;
}

int main(void){
    int a[13]={-55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33};
    int si;
    int **show = threeSum(a, 13, &si);

    for(int i=0;i<si;i++){
        printf("[");
        printf("%d ", show[i][0]);
        printf("%d ", show[i][1]);
        printf("%d", show[i][2]);
        printf("]\n");
    }
    

    return 0;
}