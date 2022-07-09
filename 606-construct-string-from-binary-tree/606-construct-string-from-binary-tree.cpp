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
    void preorder(TreeNode* root,string &s){
        // base case
        if(root==NULL or (root->left==NULL and root->right==NULL)){
            return;
        }
        if(root->left==NULL and root->right!=NULL){
            s+="()";
        } 
         if(root->left){
            s+='('+to_string(root->left->val);
            preorder(root->left,s);         
            s.push_back(')');
        }
         if(root->right){
            s+='('+to_string(root->right->val);
            preorder(root->right,s);
            s.push_back(')');
        }
        // return;
        
    }
    string tree2str(TreeNode* root) {
        string s="";
        s+=to_string(root->val);
        preorder(root,s);
        return s;
    }
};