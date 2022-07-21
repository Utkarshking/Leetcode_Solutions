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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        auto it = *max_element(nums.begin(), nums.end());
        auto maxitr=max_element(nums.begin(),nums.end());
        TreeNode* node=new TreeNode(it);
        vector<int>leftsubtree(nums.begin(),maxitr);
        node->left=constructMaximumBinaryTree(leftsubtree);
        vector<int>rightsubtree(++maxitr,nums.end());
        node->right=constructMaximumBinaryTree(rightsubtree);
        return node;
        
    }
};