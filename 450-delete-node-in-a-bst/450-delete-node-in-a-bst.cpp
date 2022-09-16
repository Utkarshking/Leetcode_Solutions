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
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root==NULL)  return root;
        if(root->val==key) return helper(root);
        TreeNode* temp=root;
        while(root){
            if(root->val>key){
                if(root->left!=NULL and root->left->val==key){
                    // the root left is not null and we found the element
                    // and we went to the helper function to perform the further functionality
                    root->left=helper(root->left);
                    break;
                }
                else{
                    // if not we will move further in the iteration
                    root=root->left;
                }
            }
            else{
                if(root->right!=NULL and root->right->val==key)
                {
                    // we found the element and we want to delete the particular node
                    // and thus we need to attach the further subtree to it 
                    root->right=helper(root->right);
                    break;
                }
                else{
                    // we havent found the tree and thus will further move to the 
                    // further part of the iteration
                    root=root->right;
                }
            }
        }
            return temp;
    }
        TreeNode* helper(TreeNode* root){
            if(root->left==NULL) return root->right;
            else if(root->right==NULL) return root->left;
            TreeNode* rightchild=root->right;
            TreeNode* lastright=findlastright(root->left);
            lastright->right=rightchild;
            return root->left;
        }
        TreeNode* findlastright(TreeNode* root){
            while(root){
                if(root->right==NULL) return root;
                root=root->right;
            }
            return NULL;
        }
};