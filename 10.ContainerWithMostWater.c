#include <stdio.h>

int maxArea(int *height, int heightSize){
    int left, right, max, w, h, temp;
    left = 0;right = heightSize-1;max=0;

    while(left!=right){
        w = right - left;
        if(height[left]<=height[right]){
            h = height[left];
            left++;
        }else{
            h = height[right];
            right--;
        }
        temp = w*h;
        if(max<temp)
            max = temp;
    }

    return max;
}

int main(void){

    int height[9] = {1,8,6,2,5,4,8,3,7};
    printf("max : %d \n", maxArea(height, 9));

    return 0;
}