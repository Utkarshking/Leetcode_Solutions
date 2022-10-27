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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
       if(headA==NULL or headB==NULL) return NULL;
        ListNode* dummy1=headA;
        ListNode* dummy2=headB;
        // if dummy1 and dummy2 have the different lengths 
        while(dummy1!=NULL and dummy2!=NULL and dummy1!=dummy2){
                dummy1=dummy1->next;
                dummy2=dummy2->next;
                if(dummy1==dummy2) return dummy1;
            if(dummy1==NULL) dummy1=headB;
            if(dummy2==NULL)  dummy2=headA;
        }
        return dummy1;
    }
};