#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2147483647
#define MIN -2147483648

int myAtoi(char *s){
    char check= '+';
    int i, len;
    long long result;
    len = strlen(s);
    i=0;
    result = 0;

    while(s[i]==' '){ //remove space(space ascii = 32)
        i++;
    }

    if(s[i]=='+' || s[i]=='-'){ // check + or -. (+ ascii = 43, - ascii = 45)
        if(s[i]=='-')
            check = '-';        
        i++;
    }

    while(s[i]>=48 && s[i]<=57){
        result *=10;
        result += s[i]-48;
        i++;

        if(-1*result<=MIN && check=='-'){
            result = -MIN;
            break;
        }
        if(result>MAX){
            result = MAX;
            break;
        }
    }
    if(check=='-')
        result*=-1;

    return result;
}

int main(void){
    char *s = "-2147483648";
    printf("%d\n", myAtoi(s));


    
}