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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // find it can be and insert
        // it can be some leaf position
        
        // base case 
        // if the root is null 
        // then we will just return the value to be inserted in the binary search tree
        if(root==NULL) return new TreeNode(val);
        TreeNode* curr=root;
        while(curr){
            if(curr->val<=val){
                if(curr->right!=NULL) curr=curr->right;
                else{
                    TreeNode* temp=new TreeNode(val);
                    curr->right=temp;
                    break;
                }   
            }
            else{
                if(curr->left!=NULL) curr=curr->left;
                else{
                    TreeNode* temp=new TreeNode(val);
                    curr->left=temp;
                    break;
                }
            }
            
        }
        return root;
    }
};