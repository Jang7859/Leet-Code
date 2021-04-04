#include <stdio.h>
#include <stdlib.h>

int arr[11], N;
void dfs(int depth){
    int i;
    if(depth>N){
        for(i=1;i<=N;i++){
            printf("%d", arr[i]);
        }
        printf("\n");
        return ;
    }
    for(i=1;i<=6;i++){
        arr[depth] = i;
        dfs(depth+1);
    }
}

int main(void){

    N=4;
    dfs(1);

    return 0;
}