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
       ListNode sd(0);
       ListNode ld(0);
       ListNode* small = &sd;
       ListNode* large = &ld;
       while(head != NULL){
            if(head->val < x){
                small->next = head;
                small = small->next;
            }else{
                large->next = head;
                large = large->next;
            }
        head = head->next;
       } 
       large->next = NULL;
       small->next = ld.next;
       return sd.next;
    }
};