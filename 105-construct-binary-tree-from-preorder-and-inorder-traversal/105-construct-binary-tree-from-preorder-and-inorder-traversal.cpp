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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inorder_map;
        for(int i=0;i<inorder.size();i++){
            inorder_map[inorder[i]]=i;
        }
        // for(auto it:inorder_map) cout<<it.first<<" "<<it.second<<endl;
        TreeNode* root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,
                                inorder_map);
            return root;
        }
        TreeNode* buildTree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&inorder_map){
                // base condition
                if(preStart>preEnd or inStart>inEnd){
                    return NULL;
               }
            TreeNode* root=new TreeNode(preorder[preStart]);
            int in_root=inorder_map[root->val];
            int numleft=in_root-inStart;
            // left subtree part
            root->left=buildTree(preorder,preStart+1,preStart+numleft,inorder,inStart,in_root-1,inorder_map);        
              
            // right subtree part
            root->right=buildTree(preorder,preStart+numleft+1,preEnd,inorder,in_root+1,inEnd,inorder_map);
        return root;
        }
};