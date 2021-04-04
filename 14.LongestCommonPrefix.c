#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0)
        return "";
    if(strsSize==1)
        return strs[0];

    int i, j, count, sw;
    j=0; count=0; sw=1;
    while(sw){
        for(i=0;i<strsSize-1;i++){
            if(strs[i][j]!=strs[i+1][j]){
                sw = 0;
                break;
            }
            if(strs[i][j]==0){
                sw = 0;
                break;
            }
        }
        count++;
        j++;
    }

    if(sw==0)
        count--;

    return strndup(*strs, count);      

}

int main(void){

    char *strs[2] = {"a","a"};

    printf("%s\n",longestCommonPrefix(strs, 2));
    return 0;
}