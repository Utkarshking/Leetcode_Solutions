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
    bool isSymmetric(TreeNode* root) {
        // in isymmetrichelp function we are passing the whole right and left subtree
      return(root==NULL) ||  isSymetrricHelp(root->left,root->right); 
    }
    bool isSymetrricHelp(TreeNode* left,TreeNode* right){
        // left and right subtree came to at all without being returned as false
        if(left==NULL||right==NULL){
            return left==right;
        }
        // not symmetric at all
        if(left->val!=right->val) return false;
        return isSymetrricHelp(left->left,right->right) and
            isSymetrricHelp(left->right,right->left);
    }
};