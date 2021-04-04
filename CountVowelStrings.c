#include <stdio.h>

char v[52]={'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a',
'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a'};
char arr[5] = {'a','e','i','o','u'};
int countVowelStrings(int n){
    

    int count = 0;
    if(n==0)
        return 1;
    for(int i=0;i<5;i++){
        v[n] = arr[i];
        if(v[n]<v[n+1])
            continue;
        count += countVowelStrings(n-1);
    }

    return count;

}

int main(void){
    printf("%d\n", countVowelStrings(8));
}