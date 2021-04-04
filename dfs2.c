#include <stdio.h>
#include <stdlib.h>

int arr[100][100] = {0};
int cnt=0;
void dfs(int n){
    
    int i,j;
    for(i=1;i<100;i++){
        for(j=i+1;j<100;j++){
            if(arr[i][j]!=0){

            }
        }
    }

}

void push(int a, int b){
    arr[a][b] = 1;
    arr[b][a] = 1;
}

void back(int a, int b){
    arr[a][b] = 0;
    arr[b][a] = 0;
}

int main(void){

    int i;
    
    push(1,2);
    push(1,5);
    push(2,5);
    push(2,3);
    push(5,6);

    dfs(1);

    printf("%d\n", cnt-1);
}