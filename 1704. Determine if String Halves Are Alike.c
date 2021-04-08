bool check(char s){
    return s=='a'||s=='e'||s=='i'||s=='o'||s=='u'||s=='A'||s=='E'||s=='I'||s=='O'||s=='U';
}

bool halvesAreAlike(char * s){
    int num=0;
    int second = strlen(s);
    int first = second/2;
    
    for(int i=0;i<first;i++){
        if(check(s[i])) ++num;
    }
    for(int i=first;i<second;i++){
        if(check(s[i])) --num;
    }
    
    
    
    return !num;
}