bool solve(int** matrix, int left, int right, int row, int target){
    if(left<=right){
        int mid = left+(right-left)/2;
        int value = matrix[row][mid];
        if(value==target) return true;
        
        if(value>target) return solve(matrix, left, mid-1, row, target);
        else return solve(matrix, mid+1, right, row, target);
        
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = 0;
    int i;
    //Find row
    for(i=0;i<matrixSize;i++){
        if(matrix[i][*matrixColSize-1]>=target) break;
    }
    if(i==matrixSize) return false;
    
    //Find the target in row (using merge)
    return solve(matrix, 0, *matrixColSize-1, i, target);
}