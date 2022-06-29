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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()!=inorder.size()) return NULL;
        map<int,int>inorder_map;
        for(int i=0;i<inorder.size();i++){
                inorder_map[inorder[i]]=i;
        }
        TreeNode* root=buildTreefrompos(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inorder_map);
        return root;
     }
    TreeNode* buildTreefrompos(vector<int>&inorder,int inStart,int inEnd,vector<int>&postorder,int postStart
                              ,int postEnd,map<int,int>&inorder_map){
            // base condition on which recursion ends
            // and also if we reach the child will which is then not present so
            // in that case we can return a  NULL
            if(inStart>inEnd or postStart>postEnd) return NULL;
        // node will have the root and because of the preorder array and also the preend as we can 
        // identify the last element is actually the root of the tree
            TreeNode* root=new TreeNode(postorder[postEnd]);
        // and we can have the index of the root of the tree where it lying the inorder traversal array
        // we can get because we already got the root of the tree and we can have its value incorporated
            int rootidx_inorder=inorder_map[root->val];
        // we can keep the track of the elements which are present for the part of the left subchild
        // this can auto track all the elements when the functions are recursively called
            int remainelements_postorder=rootidx_inorder-inStart;
        
    root->left=buildTreefrompos(inorder,inStart,rootidx_inorder-1,postorder,postStart,postStart+remainelements_postorder-1,inorder_map);
        root->right=buildTreefrompos(inorder,rootidx_inorder+1,inEnd,postorder,postStart+remainelements_postorder,postEnd-1,inorder_map);
        return root;
    
    
    }
    
};