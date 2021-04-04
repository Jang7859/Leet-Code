#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int arr[9][9];
bool visited[9];

void push(int i, int j){
    arr[i][j] = 1;
    arr[j][i] = 1;
}

void bfs(int start){
    int queue[10];
    int front = -1, tail = -1;
    int temp;
    queue[++tail] = start;
    visited[start] = true;
    
    while(front!=tail){
        temp = queue[++front];
        printf("%d ", temp);
        for(int i=1;i<9;i++){
            if(arr[temp][i]==1 && !visited[i]){
                queue[++tail] = i;
                visited[i] = true;
            }
        }
    }
}

void dfs(int x){
    int temp;
    visited[x] = true;
    printf("%d ", x);
    for(int i = 1;i<9;i++){
        temp = arr[x][i];
        if(temp==1 && !visited[i]) dfs(i);
    }
}

int main(void){
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            arr[i][j] = 0;
        }
        visited[i] = false;
    }
    
    push(1,2);
    push(1,3);
    push(1,8);
    push(3,4);
    push(3,5);
    push(4,5);
    push(2,7);
    push(7,8);
    push(7,6);
    
    bfs(1);
    
    
    return 0;
}
