#include <stdio.h>



int concatenatedBinary(int n){
    long long int ans = 0;
    long long temp;
    unsigned int temp2, count=0;
    int j;
    
    for(int i=n;i>0;i--){
        temp = i;
        temp2=i;
        for(j=0;j<count;j++){
            temp =(temp<<1)%1000000007;
        }
        ans+=temp;
        
        while(temp2!=0){
            temp2 = temp2>>1;
            count++;
        }
    }
    
    return ans;
}

int main(void){

    printf("%d", concatenatedBinary(3));

    return 0;
}