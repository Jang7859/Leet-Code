#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x){

    if(x<0 || (x%10 == 0 && x!=0))
        return false;

    int temp=0;
    
    while(x>temp){
        temp = temp*10 + x%10;
        x/=10;
    }

    return temp == x || temp/10 ==x;
    
}

int main(void){
    int num = 10;
    bool check = isPalindrome(num);
    if(check)
        printf("ture\n");
    else 
        printf("false\n");

    return 0;
}