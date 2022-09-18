/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        int curr=root->val;
        // move right since the node we are searching is indeed greater
        if(curr<p->val and curr<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        // move left since the node which we are finding is indeed smaller 
        // than the current value
        if(curr>p->val and curr>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
};