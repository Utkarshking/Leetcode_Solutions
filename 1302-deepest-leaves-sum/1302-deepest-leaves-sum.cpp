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
    void recursion(TreeNode* root, int &sum){
        if(!root) return;
        int ans;
        vector<vector<int>>level_order;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
               level.push_back(node->val);
            }
            level_order.push_back(level);
        }
       for(auto it:level_order){
            ans=0;
           for(auto vctr:it){
               ans+=vctr;
           }
       }
         sum=ans;
    }
    int deepestLeavesSum(TreeNode* root) {
     if(!root) return 0;
        int sum=0;
        recursion(root,sum);
        return sum;
    }
};