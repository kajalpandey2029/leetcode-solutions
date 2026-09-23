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
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {

            // Store the next node before changing the link
            ListNode* next = curr->next;

            // Reverse the current node's link
            curr->next = prev;

            // Move prev forward
            prev = curr;

            // Move curr forward
            curr = next;
        }

        // prev is now the new head
        return prev;
    }
};