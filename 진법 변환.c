#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

void change_base(int n, int b){
    if(n<=0) return;
    int r;
    r = n%b;
    change_base(n/b, b);
    
    if(r<10)printf("%d", r);
    else printf("%c", r-10+'A');
}

int main(void){
    int num, base;
    printf("수와 진법을 입력하세요(100 5) : ");
    scanf("%d %d", &num, &base);
    if(num==0 || base == 0) return 1;
    
    if(num<0){
        printf("-");
        --num;
        num = ~num;
    }
    
    change_base(num, base);
    printf("\n");
    
    return 0;
}