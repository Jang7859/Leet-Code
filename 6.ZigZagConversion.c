#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * convert(char * s, int numRows){

    if(numRows==1)
        return s;

    int i, k, index, pivot, check;
    k=0;
    int n = strlen(s);
    char *result = (char*)malloc(sizeof(char)*n+1);
    result[n] = '\0';   
    
    for(i=0;i<numRows;i++){
        index = i;
        pivot = numRows-1;
        if(index == 0 || index == numRows-1){
            for(index=i;index<n;index+=((numRows)*2-2)){
                result[k] = s[index];
                k++;
            }            
        }else{
            check = 0;
            for(index=i;index<n;){
                result[k] = s[index];
                k++;
                if(check%2 == 0){
                    index = index + (numRows-1-i)*2;
                }else{
                    index = index + (pivot - (numRows-1-i))*2;
                }
                check++;
            }
        }
        
    }

    return result;
}

int main(void){

    char *s = "A";
    printf("%s\n", convert(s, 1));

    return 0;
}