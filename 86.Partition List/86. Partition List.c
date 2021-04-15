//////C C C C C C C C C/////////


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x){
    
    
    struct ListNode* a, *b, *temp_a, *temp_b;
    a = (struct ListNode*)malloc(sizeof(struct ListNode));
    a->next = NULL;
    b = (struct ListNode*)malloc(sizeof(struct ListNode));
    b->next = NULL;
    temp_a = a;
    temp_b = b;
    while(head){
        
        if(head->val >= x){
            struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = head->val;
            temp->next = NULL;
            
            temp_b->next = temp;
            temp_b = temp_b->next;
            
        }else{
            struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = head->val;
            temp->next = NULL;
            temp_a->next = temp;
            temp_a = temp_a->next;
        }
        head = head->next;
    }
    if(!a->next) return b->next;
    a = a->next;
    b = b->next;
    temp_a->next = b;
    
    return a;
    
}

//이것도 맞는거 같은데....
/*

void Swap(struct ListNode* left, struct ListNode* right){
    int temp = left->val;
    left->val = right->val;
    right->val = temp;
}

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* left, *right;
    left = head;
    right = head;
    
    while(right!=NULL){
        while(left!=NULL && left->val < x) left = left->next;
        if(left==NULL) break;
        
        right = left->next;
        while(right!=NULL && right->val >=x ) right = right->next;
        if(right==NULL)break;
        
        Swap(left, right);
        left = left->next;
    }
    
    return head;
}
*/





/////// C++ C++ C++ C++ C++ C++ ////////
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* a = new ListNode(0, nullptr);
        ListNode* b = new ListNode(0, nullptr);
        ListNode* temp_a = a;
        ListNode* temp_b = b;
        
        while(head){
            if(head->val< x){
                temp_a->next = new ListNode(head->val, nullptr);
                temp_a = temp_a->next;
            }else{
                temp_b->next = new ListNode(head->val, nullptr);
                temp_b = temp_b->next;
            }
            head = head->next;
        }
        
        if(a->next == NULL) return b->next;
        
        a = a->next;
        b = b->next;
        temp_a->next = b;
        
        return a;
        
    }
};