
int compare(const void*a, const void*b){
    return *(const int*)a - *(const int*)b;
}

int minMoves2(int* nums, int numsSize){
    int sum=0;
    qsort(nums, numsSize, sizeof(nums[0]), compare);
    
    int mid = nums[numsSize/2];
    
    for(int i=0;i<numsSize;++i){
        sum += abs(mid-nums[i]);
    }
    
    return sum;
}