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
        ListNode* dummy =new ListNode();
        dummy=head;
        unordered_map<ListNode*,int>mpp;
        while(dummy!=NULL){
            if(mpp.find(dummy)!=mpp.end()) return true;
            mpp[dummy]=dummy->val;
            dummy=dummy->next;
        }
        return false;
    }
};