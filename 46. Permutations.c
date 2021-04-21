void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void solve(int* arr, int numsSize, int left,int right, int **ans , int *count )
{
    int i;
    if (left == right)
    {
        *(ans+*count) = (int*)malloc(sizeof(int)*numsSize);
        memcpy(*(ans+*count), arr, numsSize * sizeof(int));
        (*count)++;
        
        return;
    }
    for (i = left; i <= right; i++) {
        swap((arr + left), (arr + i));
        solve(arr, numsSize, left+1, right, ans, count);
        swap((arr + left), (arr + i)); 
    }
        
    
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int arr[7], cnt = 0;
    arr[1] = 1;
    for(int i=2;i<=numsSize;i++){
        arr[i] = arr[i-1]*i;
    }
    int size = arr[numsSize];
    
    int** ans = (int**)malloc(sizeof(int*)*size);
    *returnSize = size;
    *returnColumnSizes = (int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        *(*returnColumnSizes+i) = numsSize;
    }
    
    solve(nums, numsSize, 0, numsSize-1, ans, &cnt);
    
    return ans;
    
}