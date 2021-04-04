#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append(char *dst, char c){
    char *p = dst;
    while(*p!='\0') p++;
    *p = c;
    *(p+1) = '\0';
}

char* intToRoman(int num){
    int temp, count, k, len;
    count = 0; k=0;
    char arr[4][2];
    char *result = (char*)malloc(sizeof(char)*20);
    result[0] = '\0';
    
    arr[0][0] = 'I';
    arr[0][1] = 'V';
    arr[1][0] = 'X';
    arr[1][1] = 'L';
    arr[2][0] = 'C';
    arr[2][1] = 'D';
    arr[3][0] = 'M';
    

    while(num>0){
        temp = num%10;
        if(temp==0){
            num/=10;
            count++;
            continue;
        }
        else if(temp<=3){
            for(int i=0;i<temp;i++){
                append(result, arr[count][0]);
            }
        }else if(temp==4){
            append(result, arr[count][1]);
            append(result, arr[count][0]);
        }else if(temp<=8){
            temp -=5;
            for(int i=0;i<temp;i++){
                append(result, arr[count][0]);
            }
            append(result, arr[count][1]);
        }else{
            append(result, arr[count+1][0]);
            append(result, arr[count][0]);
        }
        num/=10;
        count++;
    }

    //거꾸로 된 문자열 뒤집고 return 해주기.
    len = strlen(result);
    char tmp;
    for(int i=0;i<len/2;i++){
        tmp = result[i];
        result[i] = result[len-1-i];
        result[len-1-i] = tmp;
    }
    return result;
}

int main(void){
    char *result = intToRoman(10);
    printf("%s\n", result);

    return 0;
}