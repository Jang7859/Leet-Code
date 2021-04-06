bool isIdealPermutation(int* A, int ASize){
    for(int i=0;i<ASize;i++){
        if(abs(A[i]-i)>1) return false;
    }
    return true;
}



//[Time Limit Exceeded]
/*
bool isIdealPermutation(int* A, int ASize){
    int local=0, global=0;
    int i;
    

    for(int i=0;i<ASize-1;i++){
        if(A[i]>A[i+1]) local++;
        for(int j=i;j<ASize;j++){
            if(A[i]>A[j]) global++;
            if(local<global) return false;
        }
    }
    return local==global;
}
*/