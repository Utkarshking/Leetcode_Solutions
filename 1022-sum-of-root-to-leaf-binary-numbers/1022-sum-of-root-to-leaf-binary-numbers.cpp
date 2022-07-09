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
    vector<string>vec;
    void preorder(TreeNode* root,string s){
            if(root==NULL) return;
            s+=to_string(root->val);
            if(!root->left and !root->right)
            vec.push_back(s);
            preorder(root->left,s);
            preorder(root->right,s);
    }
    int sumRootToLeaf(TreeNode* root) {
        preorder(root,"");
        int res=0;
        for(auto it:vec){
             res += stoi(it, nullptr, 2);
        }
        return res;
    }
};