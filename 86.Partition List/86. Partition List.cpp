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