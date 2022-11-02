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
    private:
        ListNode* reverselist(ListNode* head){
            ListNode* dummy=NULL;
            while(head!=NULL){
                ListNode* next=head->next;
                head->next=dummy;
                dummy=head;
                head=next;
            }
            return dummy;
        }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        // finding the middle of the linked list
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // pointing to the right half of the linked list for comparison
        slow->next=reverselist(slow->next);
        slow=slow->next;
        // pointing to the left half of the linked list for comparison
        ListNode* dummy=head;
        while(slow!=NULL){
            if(dummy->val!=slow->val) return false;
            dummy=dummy->next;
            slow=slow->next;
        }
        return true;
    }
};