#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * countAndSay(int n){
    char* result = (char*)malloc(sizeof(char)*10000);
    result[0] = '1';
    result[1] = '\0';

    int i;
    for(i=1;i<n;i++){
        int j=0, k=0;
        char* temp = (char*)malloc(sizeof(char)*10000);
        while(result[j]!='\0'){
            int count=1;
            while(result[j]==result[j+1]){
                count++;
                j++;
            }
            temp[k++] = count+'0';
            temp[k++] = result[j++];
        }
        temp[k] = '\0';
        strcpy(result, temp);
        free(temp);
        
    }

    return result;
}

int main(void){

    printf("%s\n", countAndSay(30));

    return 0;
}