/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // time complexity -->O(N)
        // space complexity -->O(1)
        // ListNode* dummy =new ListNode();
        // dummy=head;
        // unordered_map<ListNode*,int>mpp;
        // while(dummy!=NULL){
        //     if(mpp.find(dummy)!=mpp.end()) return true;
        //     mpp[dummy]=dummy->val;
        //     dummy=dummy->next;
        // }
        // return false;
        
        // time complexity -->O(N)
        // space complexity -->O(1)
        // having the single or no node case
        if(head==NULL or head->next==NULL) return false;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            // slow moving at 1x
            slow=slow->next;
            // fast moving at 2x
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};