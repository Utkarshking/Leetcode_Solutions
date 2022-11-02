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
        unordered_map<ListNode*,int>mpp;
        ListNode* dummy=head;
        while(dummy!=NULL){
            if(mpp.find(dummy)!=mpp.end()) return dummy;
            mpp[dummy]=dummy->val;
            dummy=dummy->next;
        }
        return NULL;
    }
};