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
    private:
        string dupsub(TreeNode* root,unordered_map<string,int>&mpp,vector<TreeNode*>&dupsubtrees){
            if(!root) return "";
            // inorder traversal
            string str ="(";
            str+=dupsub(root->left,mpp,dupsubtrees);
            str+=to_string(root->val);
            str+=dupsub(root->right,mpp,dupsubtrees);
            str+=")";
            if(mpp[str]==1){
                dupsubtrees.push_back(root);
            }
            mpp[str]++;
            return str;
            
        }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>dupsubtrees;
        unordered_map<string,int>mpp;
        dupsub(root,mpp,dupsubtrees);
        return dupsubtrees;
    }
};