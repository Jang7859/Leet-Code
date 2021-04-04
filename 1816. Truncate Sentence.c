char * truncateSentence(char * s, int k){
    char *res = (char*)malloc(sizeof(char)*501);
    
    int i=0;
    while(s[i]!=NULL){
        
        if(s[i]==' ') k--;
        if(k==0) break;
        
        i++;
    }
    memcpy(res, s, sizeof(char)*i);
    res[i] = NULL;
    
    return res;
}