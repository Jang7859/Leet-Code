#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    int l = *(const int*)a;
    int r = *(const int*)b;
    return l-r;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize){
    
    if(numsSize<4){
        *returnSize = 0;
    }
    
    qsort((void*)nums, numsSize, sizeof(nums[0]), compare);
    
    int i,j,k;
    int l, r;
    int sum, count = 0;
    int **result = NULL;
    for(i=0;i<numsSize-3;i++){
        for(j=i+1;j<numsSize-2;j++){
            for(k=j+1;k<numsSize-1;k++){
                l = k+1;
                sum = nums[i]+nums[j]+nums[k]+nums[l];
                while(sum<=target && l<numsSize){
                    if(sum==target&&(nums[l]!=nums[l-1] && (l-1)!=k)){
                        count++;
                        result = (int**)realloc(result, sizeof(int*)*count);
                        result[count-1] = (int*)malloc(sizeof(int)*4);
                        result[count-1][0] = nums[i];
                        result[count-1][1] = nums[j];
                        result[count-1][2] = nums[k];
                        result[count-1][3] = nums[l];
                    }
                    sum = nums[i]+nums[j]+nums[k]+nums[l];
                    l++;
                }
            }
        }
    }
    *returnSize = 4;
    
    return result;
}

int main(void){
    int a[6] = {1,0,-1,0,2,-2};
    int si;
    int **show = fourSum(a, 6, 0, &si);

    for(int i=0;i<si;i++){
        printf("[");
        printf("%d ", show[i][0]);
        printf("%d ", show[i][1]);
        printf("%d", show[i][2]);
        printf("%d", show[i][3]);
        printf("]\n");
    }
    

    return 0;
}