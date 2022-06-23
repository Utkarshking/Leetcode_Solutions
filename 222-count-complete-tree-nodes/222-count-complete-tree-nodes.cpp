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
    int  recursion(TreeNode* root,int cnt){
        // inorder traversal
        // if(!root) return;
        // if(root->left) recursion(root->left,cnt);
        // cnt++;
        // if(root->right) recursion(root->right,cnt);
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            cnt+=size;
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left){
                q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        int cnt=0;
        int nodes=recursion(root,cnt);
        return nodes;
    }
};