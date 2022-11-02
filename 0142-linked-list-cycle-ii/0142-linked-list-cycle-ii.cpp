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
    ListNode *detectCycle(ListNode *head) {
        // time complexity -->O(N)
        // space complexity -->O(N)
        // space used in unordered map(which is the hash table)
        // unordered_map<ListNode*,int>mpp;
        // ListNode* dummy=head;
        // while(dummy!=NULL){
        //     if(mpp.find(dummy)!=mpp.end()) return dummy;
        //     mpp[dummy]=dummy->val;
        //     dummy=dummy->next;
        // }
        // return NULL;
        
        
        // time complexity -->~O(N)
        // space complexity -->O(1)
        if(head==NULL or head->next==NULL) return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* entry=head;
        while(fast->next!=NULL and fast->next->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
                // now in this case 
                // l1=l2- noofturns*cyclelength
                // so finding the starting point of the loop in the linked list
                if(fast==slow){
                while(entry!=slow){
                    entry=entry->next;
                    slow=slow->next;
                }
                // now entry has reached the starting the point of the loop in the linked list
            return entry;
            }
        }
        return NULL;
    }
};