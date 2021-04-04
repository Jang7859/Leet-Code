#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };
 

void push(struct ListNode ** head, int val){
    struct ListNode* temp = *head;
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    
    if(temp==NULL)
        *head = node;
    else{
        while(temp->next!=NULL) temp=temp->next;
        temp ->next = node;
    }   
    
}

void delete(struct ListNode **head){
    struct ListNode* temp = *head;
    *head = temp->next;
    free(temp);
}

int compare(const void*a, const void*b){
    int l = *(const int*)a;
    int r = *(const int*)b;
    
    return l-r;
    }


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode* ans = NULL;
    int arr[listsSize];
    int i=0, j=0, count=0;
    int index, val;
    
    while(1){
        i=0;
        while(i<listsSize && lists[i]==NULL){ //초기값 설정
            i++;
        }
        if(i==listsSize) break;
        else{
            index = i;
            val = lists[i][0].val;
        }
        
        for(j=i+1;j<listsSize;j++){
            if(lists[j]==NULL) continue;
            if(lists[j][0].val<val){
                i=j;
                index = i;
                val = lists[i][0].val;
            }
        }       
        
        push(&ans, val);
        delete(&lists[i]);
        
    }
    
    
    
    
    return ans;
    
}


int main(void){

    struct ListNode *arr[3] = {NULL};
    push(&arr[0], 1);
    push(&arr[0], 4);
    push(&arr[0], 5);
    push(&arr[1], 1);
    push(&arr[1], 3);
    push(&arr[1], 4);
    push(&arr[2], 2);
    push(&arr[2], 6);

    struct ListNode* result = mergeKLists(arr, 3);
    struct ListNode * temp = result;
    

    for(int i=0;i<)

    return 0;
}