#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//brute force
// char * longestPalindrome(char * s){
//     int length = strlen(s);
//     int count=0, index;
//     char l, r;
    
//     for(int i=0;i<length -1;i++){
//         l = s[i];
//         for(int j=i+1;j<length;j++){
//             if(s[i]==s[j]){
//                 if(count<j-i){
//                     index = i;
//                     count = j-i;
//                 }
//             }
//         }
//     }
    
//     char* result = (char*)malloc(sizeof(char)*(count+1));
//     for(int i=0;i<=count;i++){
//         result[i] = s[index+i];
//     }
    
//     return result;
// }

//맨체스터 알고리즘.
char* longestPalindrome(char* s) {
    
    if(!s[0])
        return s;
    int len = strlen(s);
    
    int i, j, k, count, index, temp;
    k=0;count=1;index = 0;
    
    while(k<len){
        i=k;
        j=k;
        while(j<len-1 && s[j]==s[j+1]) j++;
        k=j+1;
        while(i>0 && j<len-1 && s[i-1]==s[j+1]){
            i--;
            j++;
        }
        temp = j-i+1;
        if(count<temp){
            count = temp;
            index = i;
        }
    }
    
    char* result = (char*)malloc(sizeof(char)*(count+1));
    memcpy(result, &s[index], count);
    result[count] = '\0';

    return result;
}

int main(void){
    char *s = "babad";
    printf("%s\n", longestPalindrome(s));
}