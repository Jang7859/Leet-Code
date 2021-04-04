#include <stdio.h>
#include <stdlib.h>

 //Definition for singly-linked list.
 struct ListNode {
    int val;
    struct ListNode *next;
 };
 

void AddNode(struct ListNode** list, int val){
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = val;
    temp->next = NULL;
    
    if(*list==NULL)
        *list = temp;
    else{
        struct ListNode* jump;
        jump = *list;
        while(jump->next!=NULL){
            jump = jump->next;
        }
        jump->next = temp;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* templ1 = l1;
    struct ListNode* templ2 = l2;
    struct ListNode* result=NULL;
    int temp, flag=0;
    
    while(templ1!=NULL && templ2!=NULL){
        temp = templ1->val + templ2->val+flag;
        AddNode(&result, temp%10);
        if(temp>=10) flag=1;
        else flag = 0;
        templ1 = templ1->next;
        templ2 = templ2->next;
    }
    
    while(templ1!=NULL){
        temp = templ1->val + flag;
        AddNode(&result, temp%10);
        if(temp>=10) flag = 1;
        else flag=0;
        templ1 = templ1->next;
    }
    while(templ2!=NULL){
        temp = templ2->val + flag;
        AddNode(&result, temp%10);
        if(temp>=10) flag = 1;
        else flag=0;
        templ2 = templ2->next;
    }
    if(flag==1)
        AddNode(&result, 1);
    
    return result;
}

int main(void){

    struct ListNode* l1 =NULL;
    AddNode(&l1, 9);
    AddNode(&l1, 9);
    AddNode(&l1, 9);
    AddNode(&l1, 9);
    struct ListNode* l2 =NULL;
    AddNode(&l2, 9);
    AddNode(&l2, 9);
    AddNode(&l2, 9);
    struct ListNode* tmp = addTwoNumbers(l1, l2);
    while(tmp!=NULL){
        printf("%d->", tmp->val);
        tmp = tmp->next;
    }

    return 0;
}