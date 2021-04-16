void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize){
    int i, j, k;
    i=0; j=numsSize-1; k=0;
    while(k<=j){
        if(nums[k]==0){
            Swap(&nums[k], &nums[i]);
            i++;
            k++;
        }else if(nums[k]==2){
            Swap(&nums[k], &nums[j]);             
            j--;
        }else{
            k++;
        }
    }
}