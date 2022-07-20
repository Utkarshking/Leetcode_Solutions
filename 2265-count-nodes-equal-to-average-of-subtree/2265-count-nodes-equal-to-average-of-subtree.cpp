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
    int returnsumheight(TreeNode* root,int &cnt){
        if(!root) return 0;
        cnt++;
        int left=returnsumheight(root->left,cnt);
        int right=returnsumheight(root->right,cnt);
        return(root->val+left+right);
    }
    void helper(TreeNode* root,int &ans){
        if(!root) return;
        int cnt=0;
        int avg=0;
        avg=(returnsumheight(root,cnt)/cnt);
        if(avg==root->val) ans++;
        helper(root->left,ans);
        helper(root->right,ans);
      
        }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};