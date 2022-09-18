/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root,long  minvalue,long maxvalue){
        if(root==NULL) return true;
        if(root->val>=maxvalue or root->val<=minvalue) return false;
        return isValidBST(root->left,minvalue,root->val) and isValidBST(root->right,root->val,maxvalue);
    }
    bool isValidBST(TreeNode* root) {
        // time complexity -->O(N)
        // space complexity -->O(1)
        // range solution
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
};