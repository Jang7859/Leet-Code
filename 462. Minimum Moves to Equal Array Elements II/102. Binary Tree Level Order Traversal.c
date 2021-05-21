/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **ans = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    int temp = 0, temp2 = 1;
    if(root==NULL) return NULL;
    
    struct TreeNode *queue[10000];
    int front = -1, tail = -1;
    queue[++tail] = root;
    
    while(front!=tail){
        *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int)*(*returnSize + 1));
        (*returnColumnSizes)[*returnSize] = tail-front;
        ans = (int**)realloc(ans, sizeof(int*)*(*returnSize+1));
        ans[*returnSize] = (int*)malloc(sizeof(int)*(tail - front));
        for(int i = front+1;i<=tail;i++){
            ans[*returnSize][i-(front+1)] = queue[i]->val;
        }
        (*returnSize)++;
        
        int index = tail;
        while((temp2--)!=0){
            front++;
            if(queue[front]->left !=NULL){ queue[++tail] = queue[front]->left; temp++;}
            if(queue[front]->right !=NULL) {queue[++tail] = queue[front]->right; temp++;}
        }
        temp2 = temp;
        temp = 0;
        
    }
    
    return ans;
    
}