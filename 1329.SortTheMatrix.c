#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void*a, const void*b){
    int l = *(const int*)a;
    int r = *(const int*)b;
    
    return l-r;
}

int** diagonalSort(int** mat, int matSize, int* matColSize){
    int i, k, index1, index2;
    int arr[100];
    
    for(i=1;i<=*matColSize;i++){
        index1=0; index2=*matColSize-i; k=0;
        while(index1<matSize && index2 < *matColSize){
            arr[k++] = mat[index1++][index2++];
        }
        qsort((void*)arr, k, sizeof(arr[0]), compare);
        
        index1=0; index2=*matColSize-i; k=0;
        while(index1<matSize && index2 < *matColSize){
            mat[index1++][index2++]=arr[k];
        }
    }
    
    for(int i=1;i<matSize;i++){
        index1 = i; index2 = 0; k =0;
        while(index1<matSize && index2<*matColSize){
            arr[k++] = mat[index1++][index2++];
        }
        
        qsort((void*)arr, k, sizeof(arr[0]), compare);
        
        index1 = i; index2 = 0; k=0;
        while(index1<matSize && index2 < *matColSize){
            mat[index1++][index2++]=arr[k];
        }
    }
    
    return mat;    
    
}

int main(void){

    int arr[3][4] = {{3,3,3,4},{2,2,2,2},{5,5,5,5}};
    int **arr2;
    int matcol[1] ={4};

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d, ",arr[i][j]);
        }
        printf("\n");
    }

    arr2 = diagonalSort(arr, 3, matcol);

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d, ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}