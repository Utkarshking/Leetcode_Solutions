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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        // temp moving pointer for the traversal of the linked list
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL or l2!=NULL or carry!=0){
            int sum=0;
            // if l1 is pointing to node and it is not null
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            // if 12 is node and not null
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            // making a new node
            ListNode* newnode= new ListNode(sum%10);
            // connecting with the temp head node
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};