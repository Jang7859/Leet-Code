#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void push(char arr[], int *cur, char val){
    arr[++(*cur)] = val;
}

char pop(char arr[], int *cur){
    return arr[(*cur)--];
}

bool isValid(char * s){
    int length = strlen(s);
    
    if(length%2!=0)
        return false;
    
    char stack[5000];
    int i, cur=-1;
    
    for(i=0;i<length;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            push(stack, &cur, s[i]);
        }else{
            if(cur==-1)
                return false;
            else if(s[i]==')'){
                if(pop(stack, &cur)!='(')
                    return false;
            }else if(s[i]=='}'){
                if(pop(stack, &cur)!='{')
                    return false;
            }else{
                if(pop(stack, &cur)!='[')
                    return false;
            }
        }
    }

    return (cur==-1);
    
}

int main(void){
    char *arr = "{}{{}}[[]]()";
    if(isValid(arr))
        printf("O\n");
    else
        printf("X\n");

    return 0;

}