#include <stdio.h>

int romanToInt(char * s){
    int i, sum=0;
    int value[89];
    value['\0'] = 0;
    value['I'] = 1;
    value['V'] = 5;
    value['X'] = 10;
    value['L'] = 50;
    value['C'] = 100;
    value['D'] = 500;
    value['M'] = 1000;
    
    for(i=0;s[i]!='\0';i++){
        if(value[s[i]] < value[s[i+1]]){
            sum-=value[s[i]];
        }else{
            sum+=value[s[i]];
        }
    }
    
    return sum;
}

int main(void){

    char *s = "LVIII";
    

    printf("%d", romanToInt(s));
}