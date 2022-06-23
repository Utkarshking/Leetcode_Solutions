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
    void recursion(TreeNode* root,int &cnt){
        if(!root) return;
        if(root->left) recursion(root->left,cnt);
        cnt++;
        if(root->right) recursion(root->right,cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt=0;
        recursion(root,cnt);
        return cnt;
    }
};