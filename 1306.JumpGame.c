#include <stdio.h>

bool solve(int* arr, int* temparr, int arrSize, int start, bool *sw){
    if(temparr[start]==1 || *sw) return false;
    else temparr[start] = 1;
    
    if(arr[start]==0){
        printf("%d", start);
        *sw = true;
        return true;
    }
    
    int left = start-arr[start];
    int right = start+arr[start];
    
    if(left<0 && right >=arrSize) return false;
    else if(left<0){
        return solve(arr, temparr, arrSize, right, sw);
    }else if(right>=arrSize){
        return solve(arr, temparr, arrSize, left,sw);
    }
    
    return solve(arr, temparr, arrSize, left,sw) || solve(arr, temparr, arrSize, right,sw);
}



bool canReach(int* arr, int arrSize, int start){
    int temparr[arrSize];
    for(int i=0;i<arrSize;i++){
        temparr[i] = 0;
    }
    bool sw = false;
    
    return solve(arr, temparr, arrSize, start, &sw);
}

int main(void){

    if(canReach)
        printf("TURE");
    else
    {
        printf("FALSE");
    }
    

    return 0;

}