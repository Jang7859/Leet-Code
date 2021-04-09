char arr[4];

void solve(char ***ans, char* digits, char *phone[], int len, int depth, int *returnSize){
    if(len==depth){
        (*returnSize)++;
        *ans = (char**)realloc(*ans, sizeof(char*)*(*returnSize));
        (*ans)[*returnSize-1] = (char*)malloc(sizeof(char)*(len+1));
        (*ans)[*returnSize-1][len] = NULL;
        for(int i=0;i<len;i++){
            (*ans)[*returnSize-1][i] = arr[i];
        }
        
        return;
    }
    
    int num = digits[depth] - '0';
    if(num==7 || num==9){
        for(int i=0;i<4;i++){
            arr[depth] = phone[num][i];
            solve(ans, digits, phone, len, depth+1, returnSize);
        }
    }else{
        for(int i=0;i<3;i++){
            arr[depth] = phone[num][i];
            solve(ans, digits, phone, len, depth+1, returnSize);
        }
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    char **ans = (char**)malloc(sizeof(char*));
    ans[0] = NULL;
    int len = strlen(digits);
    *returnSize = 0;
    if(len==0) return ans;
    char *phone[] = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    solve(&ans, digits, phone, len, 0, returnSize);
    
    return ans;
}