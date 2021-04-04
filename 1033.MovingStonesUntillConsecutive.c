#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1<num2)
        return -1;
    if(num1>num2)
        return 1;
    return 0;
}

int* numMovesStones(int a, int b, int c){
    int max, min;
    int *result = (int*)malloc(sizeof(int)*2);
    int arr[3] ={a,b,c};
    max = 0; min = 0;
    qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), compare);
    printf("%d, %d, %d\n", arr[0], arr[1], arr[2]);

    max = arr[1]-arr[0]-1 + arr[2]-arr[1]-1 ;

    if(max!= 0)
        min = 1;

    result[0]=min;
    result[1] = max;

    return result;
}

int main(void){
    int *result = numMovesStones(3,5,1);

    printf("[%d, %d]\n", result[0], result[1]);

    return 0;
}