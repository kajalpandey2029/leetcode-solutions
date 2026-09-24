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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Dummy node helps handle the case where head itself is deleted
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Two pointers
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the last node
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow->next is the node to be deleted
        ListNode* temp = slow->next;

        // Remove the node
        slow->next = slow->next->next;

        // Free memory
        delete temp;

        // Return actual head
        return dummy->next;
    }
};